/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_handle_comm_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_handle_comm_signal(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 2) {
    if (param_1 < 3) {
      if (param_1 == 0) {
        bdb_comm_start_commissioning();
      }
      else {
        if (param_1 != 1) goto _L0;
        bdb_handle_device_left(param_2);
      }
    }
    else {
      if (param_1 != 3) {
_L0:
        log_write(1,"bdb_comm.c","Invalid signal: 0x%02x",param_1);
        uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c"
                              ,0x2bf,"bdb_handle_comm_signal",&_LC6);
        iVar2 = core_globals_get();
        *(byte *)(iVar2 + 0xd5e) = *(byte *)(iVar2 + 0xd5e) & 0xfd | (byte)((uVar1 & 1) << 1);
        iVar2 = aps_secur_is_tc();
        if (iVar2 != 0) {
          if (uVar1 == 0) {
            iVar2 = 1;
          }
          else {
            iVar2 = 2;
          }
          iVar3 = core_globals_get();
          *(ushort *)(iVar3 + 0x9bc) = *(ushort *)(iVar3 + 0x9bc) & 0xfff9 | (ushort)(iVar2 << 1);
        }
        return;
      }
      bdb_handle_comm_done(param_2);
    }
  }
  return;
}

