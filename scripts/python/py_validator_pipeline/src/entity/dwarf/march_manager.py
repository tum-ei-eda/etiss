from src.entity.march.march_base import MArchBase
from src.entity.march.rv32im_zicsr_zifencei import RV32IM_zicsr_zifencei
from src.entity.march.rv32imac_zicsr import RV32IMAC_zicsr
from src.entity.march.rv32imafdc_zicsr_zifencei import RV32IMAFDC_zicsr_zifencei


class MArchManager:

    def __init__(self):
        self.supported_marchs = [
            RV32IMAC_zicsr(),
            RV32IMAFDC_zicsr_zifencei(),
            RV32IM_zicsr_zifencei()
        ]

    def march_is_supported(self, march: str) -> bool:
        is_supported = False
        for m in self.supported_marchs:
            if march == m.get_march_name():
                is_supported = True
                break
        return is_supported


    def get_march_with_name(self, march_name: str) -> MArchBase:
        march = None
        for m in self.supported_marchs:
            if march_name == m.get_march_name():
                march = m
                break
        return march
