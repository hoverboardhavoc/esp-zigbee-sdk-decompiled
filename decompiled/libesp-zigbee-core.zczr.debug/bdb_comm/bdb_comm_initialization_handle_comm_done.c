/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    pcVar4 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar3 + 0xda2));
    log_write(1,"bdb_comm.c","%s: invalid op(%d)",pcVar4,uVar2);
    __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x6c,
                  "bdb_comm_initialization_handle_comm_done",&_LC6);
  }
  else if (error != 0) {
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xda0) = 3;
    goto _L0;
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xda0) = 0;
_L0:
  bdb_comm_finish_initialization();
  return;
}

