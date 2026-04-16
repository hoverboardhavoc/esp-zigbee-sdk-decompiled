/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_signal_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_signal_comm_done(ezb_err_t error)

{
  zdo_comm_operation_t op;
  int iVar1;
  char *pcVar2;
  ezb_err_t eStack_18;
  zdo_comm_operation_t zStack_14;
  
  iVar1 = core_globals_get();
  op = *(zdo_comm_operation_t *)(iVar1 + 0xd24);
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0xd26) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd24) = 0;
  if (op == '\x02') {
    if (error == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    nwk_disc_table_reset();
    if (error == 0) goto _L0;
  }
  pcVar2 = zdo_comm_op_to_str(op);
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",pcVar2,error);
_L0:
  iVar1 = core_globals_get();
  eStack_18 = error;
  zStack_14 = op;
  (**(code **)(iVar1 + 0xd3c))(3,&eStack_18,*(code **)(iVar1 + 0xd3c));
  return;
}

