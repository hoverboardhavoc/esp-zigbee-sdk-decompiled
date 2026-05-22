/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  bVar1 = *(byte *)(iVar3 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xcc2) = 0;
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xcc0) = 0;
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
      (**(code **)(iVar3 + 0xcd4))(2,4,pcVar4,*(code **)(iVar3 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),error);
_L0:
  iVar3 = core_globals_get();
  eStack_18 = error;
  bStack_14 = bVar1;
  (**(code **)(iVar3 + 0xcd8))(3,&eStack_18,*(code **)(iVar3 + 0xcd8));
  return;
}

