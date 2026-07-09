/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_initialization_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_initialization_handle_comm_done(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 4) {
    if (param_1 < 2) goto _L0;
_L0:
    if (param_2 != 0) {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 3;
      goto _L0;
    }
  }
  else {
    if ((param_1 - 7 & 0xff) < 2) goto _L0;
_L0:
    iVar1 = core_globals_get();
    uVar2 = bdb_comm_step_to_str(*(undefined1 *)(iVar1 + 0xd4e));
    log_write(1,"bdb_comm.c","%s: invalid op(%d)",uVar2,param_1);
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x6d,
                  "bdb_comm_initialization_handle_comm_done",&_LC6);
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4c) = 0;
  zdo_dev_set_joined(1);
_L0:
  bdb_comm_finish_initialization();
  return;
}

