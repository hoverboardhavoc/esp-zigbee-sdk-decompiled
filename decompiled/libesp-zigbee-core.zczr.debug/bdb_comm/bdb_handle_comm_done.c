/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void bdb_handle_comm_done(zdo_comm_result_t *result)

{
  zdo_comm_operation_t op;
  byte bVar1;
  ezb_err_t error;
  int iVar2;
  char *pcVar3;
  
  op = result->last_op;
  error = result->error;
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0xd4e);
  if (bVar1 == 2) {
    bdb_comm_network_steering_handle_comm_done(op,error);
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      bdb_comm_initialization_handle_comm_done(op,error);
    }
    else {
      if (bVar1 != 1) goto _L0;
      bdb_comm_initiator_handle_comm_done(op,error);
    }
  }
  else {
    if (bVar1 == 4) {
      iVar2 = core_globals_get();
      pcVar3 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar2 + 0xd4e));
      log_write(1,"bdb_comm.c","%s: run in wrong state",pcVar3);
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x29c,
                    "bdb_handle_comm_done",&_LC6);
_L0:
      iVar2 = core_globals_get();
      log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar2 + 0xd4e));
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x2a0,
                    "bdb_handle_comm_done",&_LC6);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (bVar1 == 5) {
      bdb_comm_target_handle_comm_done(op,error);
    }
    else {
      if (bVar1 != 3) goto _L0;
      bdb_comm_network_formation_handle_comm_done(op,error);
    }
  }
  return;
}

