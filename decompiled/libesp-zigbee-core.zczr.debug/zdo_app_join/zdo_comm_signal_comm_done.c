/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_signal_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_signal_comm_done(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_18;
  char cStack_14;
  
  iVar2 = core_globals_get();
  cVar1 = *(char *)(iVar2 + 0xcc0);
  iVar2 = core_globals_get();
  *(undefined2 *)(iVar2 + 0xcc2) = 0;
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xcc0) = 0;
  if (cVar1 == '\x02') {
    if (param_1 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    nwk_disc_table_reset();
    if (param_1 == 0) goto _L0;
  }
  uVar3 = zdo_comm_op_to_str(cVar1);
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",uVar3,param_1);
_L0:
  iVar2 = core_globals_get();
  iStack_18 = param_1;
  cStack_14 = cVar1;
  (**(code **)(iVar2 + 0xcd8))(3,&iStack_18,*(code **)(iVar2 + 0xcd8));
  return;
}

