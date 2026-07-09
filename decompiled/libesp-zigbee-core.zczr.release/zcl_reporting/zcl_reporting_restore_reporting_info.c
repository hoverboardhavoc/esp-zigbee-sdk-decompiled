/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_restore_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_restore_reporting_info(uint param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  char local_30;
  byte bStack_2f;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  byte bStack_29;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined2 uStack_23;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 auStack_1d [9];
  short sStack_14;
  char cStack_12;
  
  memset(&local_30,0,0x20);
  do {
    ds_zcl_reporting_info_itor_read(&local_30);
    do {
      cVar1 = local_30;
      if (cStack_12 != '\0') {
        return 0;
      }
      if (bStack_2f != param_1) break;
      iVar4 = zcl_reporting_info_create
                        (param_1,uStack_2e,local_30 != '\0',uStack_2c,uStack_2a,
                         (uint)bStack_29 | (uStack_28 & 0xff) << 8,uStack_28 >> 8 & 0xffff);
      if (iVar4 == 0) {
        uVar3 = 1;
_L0:
        ds_internal_remove_entry(10,0xffffffff,0);
        iVar4 = core_globals_get();
        piVar2 = *(int **)(iVar4 + 0xd34);
        while ((piVar2 + -1 != (int *)0xfffffffc &&
               ((piVar2[-1] == 0 || (iVar4 = zcl_reporting_store_reporting_info(), iVar4 == 0))))) {
          piVar2 = (int *)*piVar2;
        }
        return uVar3;
      }
      *(ushort *)(iVar4 + 0x10) = CONCAT11(uStack_24,uStack_28._3_1_);
      if (cVar1 == '\0') {
        *(undefined2 *)(iVar4 + 0x12) = uStack_23;
        *(ushort *)(iVar4 + 0x28) = CONCAT11(uStack_20,uStack_21);
        *(short *)(iVar4 + 0x2a) = (short)((uint)_uStack_20 >> 8);
        memcpy((void *)(iVar4 + 0x18),auStack_1d,8);
      }
      iVar4 = zcl_reporting_info_add(iVar4);
      if (iVar4 != 0) {
        uVar3 = 0xffffffff;
        goto _L0;
      }
    } while (cStack_12 != '\0');
    sStack_14 = sStack_14 + 1;
  } while( true );
}

