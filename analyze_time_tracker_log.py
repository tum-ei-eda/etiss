#!/usr/bin/python3

import argparse
import pandas as pd
from pathlib import Path

parser = argparse.ArgumentParser()

parser.add_argument("log_file")
parser.add_argument("--out-dir", default=".")

args = parser.parse_args()

log_file = args.log_file

df = pd.read_csv(log_file)

df['delta_instr'] = df['instr_cnt'].diff()
df['delta_time'] = df['time'].diff()

# Avoid division by zero or NaNs in the first row
df['sim_mips'] = (df['delta_instr'] / df['delta_time']) / 1e6

print(df)

# Rolling window over 100 blocks
# df['sim_mips_smooth'] = df['sim_mips'].rolling(window=100, min_periods=1).mean()

df2 = df.iloc[1:].copy()
df2['sim_time'] = pd.to_datetime(df2['time'], unit='s')
df2.set_index('sim_time', inplace=True)

print(df2)

# Resampling over 10us
resampled_mips = df2['sim_mips'].resample('0.1ms').mean()
resampled_mips = resampled_mips.interpolate()

# mean_mips = df2["sim_mips"].mean()
mean_mips2 = resampled_mips.mean()



print(resampled_mips)

import matplotlib.pyplot as plt

plt.figure(figsize=(12, 4))
# plt.plot(df2['sim_time'], df['sim_mips'], label='Per Block MIPS', alpha=0.4)
plt.plot(resampled_mips.index, resampled_mips, label='Resampled MIPS', alpha=1.0)
# plt.plot(df['time'], df['sim_mips'], label='Per Block MIPS', alpha=0.4)
# plt.plot(df['time'], df['sim_mips_instr_window'], label='Instr-Window MIPS (1000 instr)', linewidth=2)
plt.axhline(mean_mips2, color='red', linestyle='--', linewidth=1.5, label=f'Mean MIPS: {mean_mips2:.2f}')
plt.xlabel('Simulated Time (s)')
plt.ylabel('Simulation MIPS')
ax = plt.gca()
import matplotlib.dates as mdates
ax.xaxis.set_major_formatter(mdates.DateFormatter('%S.%f'))  # seconds + microseconds
plt.legend()
plt.grid(True)
plt.tight_layout()
# plt.show()
plt.savefig(Path(args.out_dir) / 'simulation_mips_plot.png', dpi=300)
plt.close()

bin_size = 100000  # or 10_000 or whatever you prefer
# bin_size = 1000000  # or 10_000 or whatever you prefer

df3 = df.iloc[1:].copy()
# df3['delta_instr'] = df3['instr_cnt'].diff()
# df3['delta_time'] = df3['time'].diff()
df3['instr_bin'] = (df3['instr_cnt'] // bin_size).astype(int)
bin_time = df3.groupby('instr_bin')['delta_time'].sum().reset_index()
bin_time['start_instr'] = bin_time['instr_bin'] * bin_size
bin_time['cumulative_time'] = bin_time['delta_time'].cumsum()
print(bin_time)

total_delta_time = bin_time["delta_time"].sum()
print("total_delta_time", total_delta_time)
print("max_cum_time", bin_time["cumulative_time"].max())

fig, ax1 = plt.subplots(figsize=(12, 4))
# Plot per-bin sim time (log Y-axis on left)
color1 = 'tab:blue'
ax1.set_xlabel('Simulated Instruction Count')
ax1.set_ylabel(f'Per-bin Sim Time (s)', color=color1)
ax1.plot(bin_time['start_instr'], bin_time['delta_time'], label=f'Per-bin Time ({bin_size} instr)',
         # color=color1)
         color=color1, linewidth=0.75, alpha=1.0)
ax1.set_yscale('log')
ax1.tick_params(axis='y', labelcolor=color1)
# ax1.grid(True, which='both', linestyle='--', linewidth=0.5)
ax1.grid(True)

ax2 = ax1.twinx()
color2 = 'tab:orange'
ax2.set_ylabel('Cumulative Sim Time (s)', color=color2)
# ax2.plot(df['instr_cnt'], df['time'], label='Cumulative Sim Time',
#          color=color2, linewidth=2, alpha=0.7)
ax2.plot(bin_time['start_instr'], bin_time['cumulative_time'], label='Cumulative Sim Time',
         color=color2, linewidth=2, alpha=0.7)
ax2.tick_params(axis='y', labelcolor=color2)

plt.ylabel('Host Time to Simulate Bin (s)')
plt.title(f'Simulation Time per {bin_size} Instructions')
# plt.yscale('log')
# plt.grid(True)
plt.tight_layout()
plt.savefig(Path(args.out_dir) / 'simulation_time_per_bin.png', dpi=300)
plt.close()
