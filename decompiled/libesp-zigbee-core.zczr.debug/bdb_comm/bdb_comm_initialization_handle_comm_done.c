/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_initialization_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_initialization_handle_comm_done(zdo_comm_operation_t op,ezb_err_t error)

{
  uint uVar1;
  undefined3 in_register_00002029;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = CONCAT31(in_register_00002029,op);
  uVar1 = uVar2;
  if (3 < uVar2) {
    uVar1 = uVar2 - 7 & 0xff;
  }
  if (uVar1 < 2) {
    iVar3 = core_globals_get();
    pcVar4 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar3 + 0xd4e));
    log_write(1,"bdb_comm.c","%s: invalid op(%d)",pcVar4,uVar2);
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x6d,
                  "bdb_comm_initialization_handle_comm_done",&_LC6);
  }
  else if (error != 0) {
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xd4c) = 3;
    goto _L0;
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xd4c) = 0;
  zdo_dev_set_joined(1);
_L0:
  bdb_comm_finish_initialization();
  return;
}

