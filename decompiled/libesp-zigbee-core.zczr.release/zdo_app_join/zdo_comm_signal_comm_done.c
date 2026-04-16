/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_signal_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_signal_comm_done(ezb_err_t error)

{
  byte bVar1;
  uint uVar2;
  zdo_comm_operation_t op;
  int iVar3;
  char *pcVar4;
  ezb_err_t eStack_18;
  byte bStack_14;
  
  iVar3 = core_globals_get();
  bVar1 = *(byte *)(iVar3 + 0xd24);
  uVar2 = (uint)bVar1;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xd26) = 0;
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xd24) = 0;
  if (uVar2 == 2) {
    if (error == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    op = nwk_disc_table_reset();
    if (error == 0) goto _L0;
    if (9 < uVar2) {
      pcVar4 = zdo_comm_op_to_str(op);
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0xd38))(2,4,pcVar4,*(code **)(iVar3 + 0xd38));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),error);
_L0:
  iVar3 = core_globals_get();
  eStack_18 = error;
  bStack_14 = bVar1;
  (**(code **)(iVar3 + 0xd3c))(3,&eStack_18,*(code **)(iVar3 + 0xd3c));
  return;
}

