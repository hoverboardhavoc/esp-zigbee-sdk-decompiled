/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_handle_comm_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_handle_comm_signal(zdo_comm_signal_t signal,void *param)

{
  undefined3 in_register_00002029;
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = CONCAT31(in_register_00002029,signal);
  if (uVar1 != 2) {
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        bdb_comm_start_commissioning();
      }
      else {
        if (uVar1 != 1) goto _L0;
        bdb_handle_device_left((zdo_comm_device_left_t *)param);
      }
    }
    else {
      if (uVar1 != 3) {
_L0:
        log_write(1,"bdb_comm.c","Invalid signal: 0x%02x",uVar1);
        uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c"
                              ,0x2c1,"bdb_handle_comm_signal",&_LC6);
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
      bdb_handle_comm_done((zdo_comm_result_t *)param);
    }
  }
  return;
}

