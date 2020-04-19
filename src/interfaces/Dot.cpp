/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "etiss/interfaces/Dot.h"

#include "etiss/FastString.h"

#include <iomanip>
#include <iostream>
#include <limits>

namespace etiss
{
namespace interfaces
{

namespace dot
{

void ValueOperationTraceGraph::defineNode(const void *id, const std::string &name)
{
    nodes_.insert(std::make_pair(id, name));
}

void ValueOperationTraceGraph::undefineNode(const void *id)
{
    nodes_.erase(id);
    currentnodes_.erase(id);
    currentdstnodes_.erase(id);
}

ValueOperationTraceGraph::Link *ValueOperationTraceGraph::link(const void *src, const void *dst)
{
    if (src == 0 || dst == 0)
        return 0;

    auto curme = currentnodes_.find(src); // find current src node
    Node *idn;
    if (curme == currentnodes_.end())
    {
        auto curdstme = currentdstnodes_.find(src);
        if (curdstme != currentdstnodes_.end()) // destination node becomes source node
        {
            currentnodes_.insert(*curdstme);
            currentdstnodes_.erase(curdstme->first);
            idn = curdstme->second;
        }
        else
        {
            // create initial src node
            idn = new Node();
            idn->id = src;
            // if (nodes_.find(src) != nodes_.end())  // link to start node if defined
            {
                Link *rl = new Link();
                rl->dst = idn;
                rl->color = "yellow";
                start.links.push_back(rl);
            }
            currentnodes_.insert(std::make_pair(src, idn));
        }
    }
    else
    {
        idn = curme->second;
    }

    // new node for dst
    Node *dstn;
    auto curdst = currentdstnodes_.find(dst);
    if (curdst != currentdstnodes_.end()) // use existing dst node
    {
        dstn = curdst->second;
    }
    else
    {
        dstn = new Node();
        dstn->id = dst;
        currentdstnodes_.insert(std::make_pair(dst, dstn));
    }

    // create link
    Link *ret = new Link();
    ret->dst = dstn;
    idn->links.push_back(ret);

    return ret;
}

void ValueOperationTraceGraph::filterTmp(Node *start_, Node *tmp, bool hideedge, const std::string &alabels,
                                         std::ofstream &out, std::unordered_set<Node *> &nnl,
                                         std::unordered_set<std::pair<const void *, const void *>> &dependencies,
                                         std::unordered_set<Node *> &declared)
{

    auto find = nodes_.find(tmp->id);
    if (find != nodes_.end()) // terminate recursion
    {

        bool revisit = true;
        if (declared.find(tmp) == declared.end())
        {
            out << "\t" << ((size_t)tmp) << " [label=\"" << find->second << "\"];\n";
            revisit = false;
            declared.insert(tmp);
        }

        if (!hideedge)
        {

            out << "\t" << ((size_t)start_) << " -> " << ((size_t)tmp);

            {
                std::string attr;

                attr = attr + ((attr.size() == 0) ? "" : " ") + "label=\"" + alabels + "\"";

                if (attr.size() > 0)
                    out << " [" << attr << "];\n";
            }
        }

        if (!revisit)
            nnl.insert(tmp);

        if (start_->id != 0) // filter start node
            dependencies.insert(std::make_pair(start_->id, tmp->id));
    }
    else
    {

        std::list<Link *> tmplinks = tmp->links;
        tmp->links.clear();

        for (auto iter = tmplinks.begin(); iter != tmplinks.end(); ++iter)
        {

            std::string l = alabels + "," + (*iter)->label;

            filterTmp(start_, (*iter)->dst, hideedge, l, out, nnl, dependencies,
                      declared); // hide link if this is not a direct link between a named node and the origin

            delete *iter;
        }
    }
}

void ValueOperationTraceGraph::flush(std::ofstream &out, const std::string &graph)
{
    std::unordered_set<std::pair<const void *, const void *>> dependencies;

    out << "digraph " << graph << "{\n";

    {
        std::unordered_set<Node *> nl;
        nl.insert(&start);

        out << "\t" << ((size_t)&start) << " [label=\"START\"];\n";

        std::unordered_set<Node *> defined;

        while (nl.size() > 0)
        {

            std::unordered_set<Node *> nnl;
            for (auto iter = nl.begin(); iter != nl.end(); ++iter)
            {
                Node *cur = *iter;
                if (cur)
                {
                    for (auto iter2 = cur->links.begin(); iter2 != cur->links.end(); ++iter2)
                    {
                        Link *curl = *iter2;
                        if (curl)
                        {
                            filterTmp(cur, curl->dst,
                                      ((cur == &this->start) && (nodes_.find(curl->dst->id) == nodes_.end())),
                                      curl->label, out, nnl, dependencies, defined);
                            /*
                            auto find = nodes_.find(curl->dst->id);
                            if (find != nodes_.end())
                            {
                                out << "\t" << ((size_t)curl->dst) << " [label=\"" <<
                            find->second << "\"];\n";
                            }
                            else
                            {
                                out << "\t" << ((size_t)curl->dst) << " [label=\"tmp\"];\n";
                            }
                            out << "\t" << ((size_t)cur) << " -> " << ((size_t)curl->dst);
                            {
                                std::string attr;
                                if (curl->color.size() > 0)
                                    attr = attr + ((attr.size()==0)?"":" ") + "color=\"" +
                            curl->color +"\""; if (curl->label.size() > 0) attr = attr +
                            ((attr.size()==0)?"":" ") + "label=\"" + curl->label +"\""; if
                            (attr.size() > 0) out << " [" << attr << "]";
                            }
                            out << ";\n";
                            nnl.push_back(curl->dst);
                            */
                            // delete curl;
                        }
                    }
                    // if (cur != &start)
                    // delete cur;
                }
            }

            nl = nnl;
        }
    }

    out << "}\n";

    out << "digraph " << graph << "_dep {\n";

    {
        std::unordered_set<const void *> present;
        for (auto iter = dependencies.begin(); iter != dependencies.end(); ++iter)
        {
            if (present.find(iter->first) == present.end())
            {
                present.insert(iter->first);
                std::string name = nodes_[iter->first]; // should always succeed due to
                                                        // filterTmp function.
                out << "\t" << ((size_t)iter->first) << " [label=\"" << name << "\"];\n";
            }
            if (present.find(iter->second) == present.end())
            {
                present.insert(iter->second);
                std::string name = nodes_[iter->second]; // should always succeed due to
                                                         // filterTmp function.
                out << "\t" << ((size_t)iter->second) << " [label=\"" << name << "\"];\n";
            }
            out << "\t" << ((size_t)iter->first) << " -> " << ((size_t)iter->second) << ";\n";
        }
    }

    out << "}\n";
}

const double ValueOperationTraceGraphStreamer::Node::Nan = std::numeric_limits<double>::quiet_NaN();

void ValueOperationTraceGraphStreamer::Node::attrToString(std::ostream &ss)
{
    std::vector<std::string> al;
    if (color && color[0])
        ss << " color=" << color;
    if (time == time)
        ss << " time=" << std::setprecision(std::numeric_limits<double>::digits10 + 2) << std::fixed << time;
    if (cluster && cluster[0])
        ss << " cluster=\"" << cluster << "\"";
    if (weight == weight)
        ss << " weight=" << weight;
    if (attrMap)
    {
        for (auto &attr : *attrMap)
        {
            ss << " " << attr.first << "=\"" << attr.second << "\"";
        }
    }
}
ValueOperationTraceGraphStreamer::Node::~Node()
{
    if (attrMap)
        delete attrMap;
}
void ValueOperationTraceGraphStreamer::Node::setAttr(const std::string &name, const std::string &value)
{
    if (!attrMap)
        attrMap = new std::map<std::string, std::string>();
    (*attrMap)[name] = value;
}

void ValueOperationTraceGraphStreamer::Link::attrToString(std::ostream &ss)
{
    // static etiss::string::form_string fs(" color=",16," label=\"",257); /// @attention testing only
    // if (color || label[0]){
    //    fs.write(1,color?color:"white",strlen(color?color:"white"));
    //    fs.writet(1,label,strlen(label),'\"',0);
    //    ss << fs;
    // }

    std::vector<std::string> al;
    if (color && color[0])
        ss << " color=" << color;
    if (label[0])
        ss << " label=\"" << label << "\"";
}

ValueOperationTraceGraphStreamer::ValueOperationTraceGraphStreamer(const std::string &file, const std::string &depfile)
{

    enable_default_graph_streaming_ = true;

    // nodeToTmpId_.rehash(1<<16);
    // currentnodes_.rehash(1<<16);
    // nodes_.rehash(1<<16);
    dependencies_.rehash(1 << 16);

    out.rdbuf()->pubsetbuf(out_buf, sizeof(out_buf));
    depout.rdbuf()->pubsetbuf(depout_buf, sizeof(depout_buf));

    out.open(file);
    depout.open(depfile);

    closed_ = (!out.is_open()) && (!depout.is_open());

    if (closed_)
    {
        std::cout << "Error: Can't open either " << file << " or " << depfile << std::endl;
        return;
    }

    out << "digraph VOT {\n";
    depout << "digraph VOTD {\n";
}
ValueOperationTraceGraphStreamer::~ValueOperationTraceGraphStreamer()
{
    close();
}

void ValueOperationTraceGraphStreamer::defineNode(const void *id, const std::string &name)
{
    if (closed_)
        return;
    nodes_.insert(id, name);
    depout << "\t" << ((size_t)id) << "[label=\"" << name << "\"];\n";
    depout.flush();
}
void ValueOperationTraceGraphStreamer::undefineNode(const void *id)
{
    if (closed_)
        return;
    nodes_.erase(id);
    Node *wnode = 0;
    // write and remove node if not linked
    {
        auto find = currentnodes_.find(id);
        if (find != 0)
        {
            if (((*find)->links_out.size() == 0))
                wnode = (*find);
            currentnodes_.erase(find);
        }
    }
    if (wnode)
        traverse(wnode);
}

ValueOperationTraceGraphStreamer::Node *ValueOperationTraceGraphStreamer::openSourceNode(const void *const src)
{
    {
        auto find = currentnodes_.find(src);
        if (find != 0) // node already exists
        {
            return *find;
        }
    }

    // create
    ValueOperationTraceGraphStreamer::Node *ret = node_alloc_.allocate(1);
    node_alloc_.construct(ret, src);
    currentnodes_.insert(src, ret);
    if (setCurrentNodeAttr)
        setCurrentNodeAttr(ret);
    return ret;
}

ValueOperationTraceGraphStreamer::Node *ValueOperationTraceGraphStreamer::openDestNode(const void *const dst,
                                                                                       Node *&cleanup)
{

    {
        auto find = currentnodes_.find(dst);
        if (find != 0) // old node exists
        {
            if ((*find)->links_out.empty())
                cleanup = *find;
            currentnodes_.erase((*find));
        }
    }

    // create
    ValueOperationTraceGraphStreamer::Node *ret = node_alloc_.allocate(1);
    node_alloc_.construct(ret, dst);
    currentnodes_.insert(dst, ret);
    if (setCurrentNodeAttr)
        setCurrentNodeAttr(ret);
    return ret;
}

void ValueOperationTraceGraphStreamer::Link::setLabel(const char *src_)
{
    size_t pos = 0;
    while ((src_[pos] != 0) && (pos < (label_size - 1)))
    {
        label[pos] = src_[pos];
        ++pos;
    }
    label[pos] = 0;
}

void ValueOperationTraceGraphStreamer::link(const void *dst, std::initializer_list<const void *> sources,
                                            const char *label)
{
    // check if Dot file is still open
    if (unlikely(closed_))
        return;

    // check if start node is valid
    if (unlikely(dst == 0))
        return;

    // create for all sources new Nodes
    Node **srcns = new Node *[sources.size()];

    size_t pos = 0;
    // get pointers for all source Nodes
    for (auto iter = sources.begin(); likely(iter != sources.end()); ++iter)
    {
        const void *ptr = *iter;
        if (likely(ptr != 0))
        {
            // get source node, if it doesn't exist it'll be created
            srcns[pos++] = openSourceNode(ptr);
        }
    }

    // we dont have a valid source pointer
    if (pos == 0)
    {
        delete[] srcns;
        return;
    }

    // get destination node, if it doesn't exist it'll be created. If it is a named TF, the link
    // can get visible -> clean up gets the pointer to this TF
    Node *cleanup = 0;
    Node *dstn = openDestNode(dst, cleanup);

    // For all valid source nodes, insert invisible link to Link pool.
    for (size_t i = 0; i < pos; ++i)
    {
        Link *l = link_alloc_.allocate(1);
        link_alloc_.construct(l, srcns[i], dstn);
        srcns[i]->links_out.insert(l);
        dstn->links_in.insert(l);
        if (label)
            l->setLabel(label);
        if (setCurrentLinkAttr)
            setCurrentLinkAttr(l, dstn, srcns, pos, sources, label);
    }

    if (cleanup)
    {
        traverse(cleanup);
    }

    if (nodes_.find(dst) != 0) // write path if path can be written
        traverse(dstn);

    delete[] srcns;
}

void ValueOperationTraceGraphStreamer::writePath()
{
    if (path.empty())
        return;

    auto src = path.back()->src;
    auto dst = path.front()->dst;
    auto sfind = nodes_.find(src->id);
    auto dfind = nodes_.find(dst->id);
    // stream value dependency
    {
        if ((dfind != 0) && (sfind != 0))
        {
            std::cout << "writePath" << std::endl;
            std::pair<const void *, const void *> p = std::make_pair(src->id, dst->id);
            if (dependencies_.find(p) == dependencies_.end())
            {
                depout << "\t" << ((size_t)src->id) << " -> " << ((size_t)dst->id) << ";\n";
                // depout.flush();
                dependencies_.insert(p);
            }
        }
    }

    if (enable_default_graph_streaming_)
    {
        if ((dfind != 0) && (sfind != 0))
        {
            if ((!hidePath) || (!hidePath(path)))
            {
                out << "\tnode  [shape=ellipse];\n";
                auto sifind = nodeToTmpId_.find(src);
                if (sifind == 0)
                {
                    sifind = nodeToTmpId_.insert(src, nnodeid_++);
                    out << "\t" << +(*sifind) << " [label=\"" << *sfind << "\"";
                    src->attrToString(out);
                    out << "];\n";
                }
                auto difind = nodeToTmpId_.find(dst);
                if (difind == 0)
                {
                    difind = nodeToTmpId_.insert(dst, nnodeid_++);
                    out << "\t" << +(*difind) << " [label=\"" << *dfind << "\"";
                    dst->attrToString(out);
                    out << "];\n";
                }
                Link *tmp = link_alloc_.allocate(1);
                link_alloc_.construct(tmp, src, dst);
                if (setMetaLinkAttr)
                {
                    setMetaLinkAttr(tmp, path);
                }
                out << "\t" << +(*sifind) << " -> " << +(*difind) << " [";
                tmp->attrToString(out);
                out << "];\n";
                // out.flush();
                link_alloc_.destroy(tmp);
                link_alloc_.deallocate(tmp);
            }
        }
    }

    if (custWritePath)
        custWritePath(path);
}

/*
static bool keepNode(ValueOperationTraceGraphStreamer::Node * n,const std::unordered_map<const void
*,ValueOperationTraceGraphStreamer::Node*,std::hash<const void*>, std::equal_to<const
void*>,etiss::ObjectPool<std::pair<const void * const,ValueOperationTraceGraphStreamer::Node*> > > & current)
{
    if (!n->links_out_.empty()) // check if there are links from this node
        return true;

    auto find = current.find(n->id);
    // check if this node is not in the set of current nodes
    if (find == current.end())
        return false;
    return find->second == n;
}
*/
static bool keepNode(ValueOperationTraceGraphStreamer::Node *n,
                     const etiss::FixedSizeHashMap<const void *, ValueOperationTraceGraphStreamer::Node *,
                                                   etiss::pointerHash<const void>> &current)
{
    if (!n->links_out_.empty()) // check if there are links from this node
        return true;

    auto find = current.find(n->id);
    // check if this node is not in the set of current nodes
    if (find == 0)
        return false;
    return *find == n;
}

void ValueOperationTraceGraphStreamer::traverse(Node *n) //,std::unordered_set<Node*> & nodes) // debug loop detection
{

    if (n == 0)
        return;

    bool dellink = false; // delete the link leading from the current end node

    Node *cur = n; // use node if no path present
    if (!path.empty())
    {
        cur = path.back()->src; // use node at end of path
        if ((nodes_.find(path.back()->dst->id) != 0) ||
            !keepNode(path.back()->dst, currentnodes_)) // check if cleanup possible // cleanup is possible if the
                                                        // originating node is a known ode or if keepNode is false
        {
            // remove link to allow further cleanup
            cur->links_out.erase(path.back());
            path.back()->dst->links_in.erase(path.back());
            dellink = true;
        }
    }
    /* debug loop detection
    if (nodes.find(cur) != nodes.end())
    {
        std::cout << "Loop detected" << std::endl;
    }
    else
    {
        nodes.insert(cur);
    }
    */

    if ((cur->links_in.size() == 0)) // end of path
    {
        if (path.size() > 0)
            writePath();
        if (dellink)
        {
            Link *dl = path.back();
            link_alloc_.destroy(dl);
            link_alloc_.deallocate(dl);
            if (!keepNode(cur, currentnodes_))
            {
                nodeToTmpId_.erase(cur);
                node_alloc_.destroy(cur);
                node_alloc_.deallocate(cur);
            }
        }
        else if (cur == n)
        {
            if (!keepNode(cur, currentnodes_))
            {
                nodeToTmpId_.erase(cur);
                node_alloc_.destroy(cur);
                node_alloc_.deallocate(cur);
            }
        }
        // nodes.erase(cur); //debug loop detection
        return;
    }

    // visit all links
    {
        std::unordered_set<Link *> &links = cur->links_in; // don't copy link list but take special care with iterator
        for (auto iter = links.begin(); iter != links.end();)
        {
            path.push(*iter);
            ++iter;      // change iter here since traverse may invalidate it
            traverse(n); //,nodes); /debug loop detection
            path.pop();
        }
    }

    if (dellink)
    {
        Link *dl = path.back();
        link_alloc_.destroy(dl);
        link_alloc_.deallocate(dl);
        if (!keepNode(cur, currentnodes_))
        {
            nodeToTmpId_.erase(cur);
            node_alloc_.destroy(cur);
            node_alloc_.deallocate(cur);
        }
    }
    else if (cur == n)
    {
        if (!keepNode(cur, currentnodes_))
        {
            nodeToTmpId_.erase(cur);
            node_alloc_.destroy(cur);
            node_alloc_.deallocate(cur);
        }
    }

    // nodes.erase(cur); //debug loop detection
}

void ValueOperationTraceGraphStreamer::close()
{
    if (closed_)
        return;
    out << "}";
    depout << "}";
    closed_ = true;
    depout.flush();
    depout.close();
    out.flush();
    out.close();
}

void ValueOperationTraceGraphStreamer::flush()
{
    depout.flush();
    out.flush();
}

const std::unordered_set<std::pair<const void *, const void *>> &ValueOperationTraceGraphStreamer::staticDependencies()
    const
{
    return dependencies_;
}

VariableDependencyGraph::VariableDependencyGraph()
{
    tmp_.rehash(1 << 13);
    // names_.rehash(1<<13); // not many changes expected. keep map small
    deps_.rehash(1 << 13); // expected behaviour is to grow at the beginning and then remain constant. bucket size
                           // should be medium large to prevent frequent rehashes at the beginning
}

void VariableDependencyGraph::link(const void *dst, const std::initializer_list<const void *> &sources)
{
    if (names_.find(dst) != names_.end())
    {
        for (auto iter = sources.begin(); iter != sources.end(); ++iter)
        {
            std::pair<const void *, const void *> tmpp(0, dst);
            if (names_.find(*iter) != names_.end())
            {
                tmpp.first = *iter;
                deps_.insert(tmpp);
            }
            else
            {
                const std::unordered_set<const void *> &srcset = tmp_[*iter];
                for (auto iter2 = srcset.begin(); iter2 != srcset.end(); ++iter2)
                {
                    tmpp.first = *iter2;
                    deps_.insert(tmpp);
                }
            }
        }
    }
    else
    {
        std::unordered_set<const void *> &tmpset = tmp_[dst];
        for (auto iter = sources.begin(); iter != sources.end(); ++iter)
        {
            if (names_.find(*iter) != names_.end())
            {
                tmpset.insert(*iter);
            }
            else
            {
                const std::unordered_set<const void *> &srcset = tmp_[*iter];
                for (auto iter2 = srcset.begin(); iter2 != srcset.end(); ++iter2)
                {
                    tmpset.insert(*iter2);
                }
            }
        }
    }
}

void VariableDependencyGraph::write(std::ostream &out, const std::string &graphname,
                                    std::function<bool(const void *, const void *, std::string &)> filterOutCon,
                                    std::function<void(const void *, std::string & /*color*/)> nodeattr)
{

    bool hideDisconnected = true;

    out << "digraph " << graphname << "{\n";

    if (!hideDisconnected)
    {
        for (auto iter = names_.begin(); iter != names_.end(); ++iter)
        {
            out << "\t" << ((size_t)iter->first) << " [label=\"" << iter->second << "\"];\n";
        }
    }
    else
    {
        std::unordered_set<const void *> cids;
        for (auto iter = deps_.begin(); iter != deps_.end(); ++iter)
        {
            std::string color;
            if ((!filterOutCon) || ((!filterOutCon(iter->first, iter->second, color))))
            {
                cids.insert(iter->first);
                cids.insert(iter->second);
            }
        }
        for (auto iter = cids.begin(); iter != cids.end(); ++iter)
        {
            std::string color;
            nodeattr(*iter, color);
            out << "\t" << ((size_t)*iter) << " [label=\"" << names_[*iter] << "\"";
            if (color.size() > 0)
                out << " color=" << color;
            out << "];\n";
        }
    }

    for (auto iter = deps_.begin(); iter != deps_.end(); ++iter)
    {
        std::string color;
        if ((!filterOutCon) || ((!filterOutCon(iter->first, iter->second, color))))
        {
            out << "\t" << ((size_t)iter->first) << " -> " << ((size_t)iter->second);
            bool hasattr = color.size() > 0;
            if (hasattr)
            {
                out << " [";

                if (color.size() > 0)
                    out << "color=" << color << " ";

                out << "]";
            }
            out << ";\n";
        }
    }

    out << "}\n";
}

#ifdef TRACEABLEFIED_H_

void VariableDependencyGraph::tf_write(const std::string & filename,
                                       const std::string & graphname,
                                       std::function<size_t(const std::string & /**<string*/,size_t /**<split pos*/> split);

#endif

} // namespace dot

static std::string depth(Dot::Node *node)
{
    if (node == nullptr)
        return "";
    if (node->parent_ == nullptr)
        return "";

    return depth(node->parent_) + "\t";
}

void Dot::AttrList::print(std::ostream &out, const std::string &appendedattr)
{
    bool none = label_.empty() && color_.empty() && appendedattr.empty();
    bool first = true;
    if (!none)
    {
        out << "[";
        if (label_.size() > 0)
        {
            out << (first ? "" : " ") << "label=\"" << label_ << "\"";
            first = false;
        }
        if (color_.size() > 0)
        {
            out << (first ? "" : " ") << " color=" << color_;
            first = false;
        }
        if (!appendedattr.empty())
        {
            out << (first ? "" : " ") << appendedattr;
            first = false;
        }
        out << "]";
    }
}
static std::string graph_getCluster(Dot::Graph *g)
{
    if (g == nullptr)
        return "";
    std::string ret = graph_getCluster(g->parent_);
    if (!ret.empty())
        ret = ret + "::";
    ret = ret + g->label_;
    return ret;
}
static std::string node_getCluster(Dot::Node *n)
{
    if (n == nullptr)
        return "";
    return graph_getCluster(n->parent_);
}
void Dot::Node::print(std::ostream &out, std::unordered_set<Link *> &icl)
{
    std::string aa;

    if (true) // add cluster as an attribute
    {
        aa = "cluster=\"";
        aa = aa + node_getCluster(this) + "\"";
    }

    out << depth(this) << " \"" << id_ << "\" ";
    AttrList::print(out, aa);
    out << ";\n";
    icl.insert(links_.begin(), links_.end());
}

void Dot::Link::print(std::ostream &out)
{
    out << depth(src_ ? src_ : dst_) << "\"" << (src_ ? src_->id_ : "0") << "\" "
        << "->" /**TODO: handle undirected*/ << " \"" << (dst_ ? dst_->id_ : "0") << "\" ";
    AttrList::print(out, "");
    out << ";\n";
}

static bool graph_contains(Dot::Graph *g, Dot::Node *n)
{
    if (g == nullptr)
        return false;
    if (n == nullptr)
        return false;
    if (n->parent_ == g)
        return true;
    return graph_contains(g, n->parent_);
}

void Dot::Graph::print(std::ostream &out, std::unordered_set<Link *> &icl)
{
    out << depth(this) << (parent_ ? "subgraph \"cluster_" : "digraph \"cluster_");
    if (!label_.empty())
        out << label_;
    else
        out << id_;
    out << "\" {\n";
    out << depth(this) << "label=\"";
    if (!label_.empty())
        out << label_;
    else
        out << id_;
    out << "\";\n\nnode;\n";

    std::unordered_set<Link *> links;
    // handle nodes first
    for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter)
    {
        if (!(*iter)->asGraph())
            (*iter)->print(out, links);
    }
    // handle sub graphs
    for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter)
    {
        if ((*iter)->asGraph())
            (*iter)->print(out, links);
    }

    for (auto iter = links.begin(); iter != links.end(); ++iter)
    {
        if (graph_contains(this, (*iter)->src_) && graph_contains(this, (*iter)->dst_))
        {
            (*iter)->print(out);
        }
        else
        {
            icl.insert(*iter);
        }
    }

    out << depth(this) << "}\n";
}

void Dot::print(std::ostream &out)
{
    for (auto iter = graphs_.begin(); iter != graphs_.end(); ++iter)
    {
        std::unordered_set<Link *> icl;
        (*iter)->print(out, icl);
        if (!icl.empty())
        {
            etiss_log(ERROR, "bug detected");
        }
    }
}

Dot::~Dot()
{
    for (auto iter = graphs_.begin(); iter != graphs_.end();)
    {
        delete *(iter++);
    }
}

Dot::Graph *Dot::createG(std::string name)
{
    Graph *ret = new Graph(this, nullptr); // note: this is why a numeral id must be a valid pointer
    ret->label_ = name;
    graphs_.push_back(ret);
    return ret;
}
Dot::Graph *Dot::createG(Dot::Graph *parent, std::string name)
{
    if (parent == nullptr)
        return nullptr;
    Graph *ret = new Graph(this, parent); // note: this is why a numeral id must be a valid pointer
    ret->label_ = name;
    return ret;
}
Dot::Node *Dot::createN(Dot::Graph *parent, const std::string &id, std::string name)
{
    if (parent == nullptr)
        return nullptr;
    if ((!id.empty()) && (idmap_.find(id) != idmap_.end()))
        return nullptr;
    Node *ret = new Node(this, parent, id);
    ret->label_ = name;
    return ret;
}
Dot::Link *Dot::createE(Dot::Node *src, Dot::Node *dst, std::string name)
{
    if ((dst == nullptr) || (src == nullptr))
        return nullptr;
    Link *ret = new Link(src, dst);
    ret->label_ = name;
    return ret;
}

Dot::Node *Dot::find(const std::string &id)
{
    auto find = idmap_.find(id);
    if (find != idmap_.end())
        return find->second;
    return nullptr;
}

Dot::Node *Dot::lopenN(const std::list<std::string> &labelpath)
{
    if (labelpath.size() < 2) // at least a graph + node name are needed
        return nullptr;
    auto iter = labelpath.begin();
    Graph *parent = 0;
    for (auto i = graphs_.begin(); i != graphs_.end(); ++i)
    {
        if ((*i)->label_ == *iter)
        {
            parent = *i;
            break;
        }
    }
    if (parent == nullptr)
        parent = createG(*iter);
    iter++;
    // travel to right sub graph
    auto niter = iter;
    niter++;
    while (niter != labelpath.end())
    {
        Graph *nparent = nullptr;
        for (auto i = parent->nodes().begin(); i != parent->nodes().end(); ++i)
        {
            if ((*i)->asGraph())
            {
                if ((*i)->label_ == *iter)
                {
                    nparent = (*i)->asGraph();
                    break;
                }
            }
        }
        if (nparent == nullptr)
            nparent = createG(parent, *iter);
        parent = nparent;
        iter++;
        niter = iter;
        niter++;
    }
    Node *ret = nullptr;
    for (auto i = parent->nodes().begin(); i != parent->nodes().end(); ++i)
    {
        if ((*i)->label_ == *iter)
        {
            ret = *i;
            break;
        }
    }
    if (ret == nullptr)
        ret = createN(parent, "", *iter);
    return ret;
}

} // namespace interfaces
} // namespace etiss
