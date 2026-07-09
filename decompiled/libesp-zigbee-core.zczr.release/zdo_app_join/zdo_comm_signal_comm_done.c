/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_signal_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_signal_comm_done(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack_18;
  byte bStack_14;
  
  iVar3 = core_globals_get();
  bVar1 = *(byte *)(iVar3 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xcc2) = 0;
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (param_1 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    nwk_disc_table_reset();
    if (param_1 == 0) goto _L0;
    if (9 < uVar2) {
      uVar4 = zdo_comm_op_to_str_part_0();
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0xcd4))(2,4,uVar4,*(code **)(iVar3 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),param_1);
_L0:
  iVar3 = core_globals_get();
  iStack_18 = param_1;
  bStack_14 = bVar1;
  (**(code **)(iVar3 + 0xcd8))(3,&iStack_18,*(code **)(iVar3 + 0xcd8));
  return;
}

