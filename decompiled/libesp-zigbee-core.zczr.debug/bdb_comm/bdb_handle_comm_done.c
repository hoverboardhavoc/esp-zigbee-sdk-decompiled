/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void bdb_handle_comm_done(undefined4 *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(undefined1 *)(param_1 + 1);
  uVar3 = *param_1;
  iVar4 = core_globals_get();
  bVar2 = *(byte *)(iVar4 + 0xd4e);
  if (bVar2 == 2) {
    bdb_comm_network_steering_handle_comm_done(uVar1,uVar3);
  }
  else if (bVar2 < 3) {
    if (bVar2 == 0) {
      bdb_comm_initialization_handle_comm_done(uVar1,uVar3);
    }
    else {
      if (bVar2 != 1) goto _L0;
      bdb_comm_initiator_handle_comm_done(uVar1,uVar3);
    }
  }
  else {
    if (bVar2 == 4) {
      iVar4 = core_globals_get();
      uVar3 = bdb_comm_step_to_str(*(undefined1 *)(iVar4 + 0xd4e));
      log_write(1,"bdb_comm.c","%s: run in wrong state",uVar3);
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x29a,
                    "bdb_handle_comm_done",&_LC6);
_L0:
      iVar4 = core_globals_get();
      log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar4 + 0xd4e));
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x29e,
                    "bdb_handle_comm_done",&_LC6);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (bVar2 == 5) {
      bdb_comm_target_handle_comm_done(uVar1,uVar3);
    }
    else {
      if (bVar2 != 3) goto _L0;
      bdb_comm_network_formation_handle_comm_done(uVar1,uVar3);
    }
  }
  return;
}

