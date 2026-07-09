/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time_ticker.o -> time_ticker_register_receiver
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void time_ticker_register_receiver(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  __atomic_fetch_or_4(s_tmtk + (param_1 >> 5) * 4,1 << (param_1 & 0x1f),5);
  iVar1 = milli_timer_is_running(s_tmtk);
  if (iVar1 == 0) {
    uVar2 = random_noncrypto_range_u32(0x3e9);
    milli_timer_start(s_tmtk,uVar2);
    return;
  }
  return;
}

