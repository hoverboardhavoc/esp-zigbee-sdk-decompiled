/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zone_table_restore(uint param_1)

{
  uint unaff_s0;
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  byte bStack_34;
  undefined1 uStack_33;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_27 [17];
  undefined2 uStack_16;
  char cStack_14;
  
  piVar1 = (int *)ezb_zcl_ias_ace_get_zone_table();
  if (piVar1 == (int *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xab,
                  "zone_table_restore","zone_table");
    goto _L0;
  }
  uStack_16 = 0;
  cStack_14 = '\0';
  ds_ias_zone_info_itor_read(&bStack_34);
  unaff_s0 = 0;
  do {
    if (cStack_14 != '\0') {
      bVar3 = false;
_L0:
      if (bVar3) {
        zone_table_refresh_stored_zones(param_1);
      }
      return;
    }
    if (bStack_34 == param_1) {
      if (*(byte *)(piVar1 + 1) <= unaff_s0) {
        bVar3 = true;
        goto _L0;
      }
      iVar4 = unaff_s0 * 0x1e;
      *(undefined1 *)(*piVar1 + iVar4) = uStack_33;
      *(undefined2 *)(*piVar1 + iVar4 + 2) = uStack_32;
      iVar2 = *piVar1 + iVar4;
      *(short *)(iVar2 + 4) = (short)uStack_30;
      *(short *)(iVar2 + 6) = (short)((uint)uStack_30 >> 0x10);
      *(short *)(iVar2 + 8) = (short)uStack_2c;
      *(short *)(iVar2 + 10) = (short)((uint)uStack_2c >> 0x10);
      *(byte *)(*piVar1 + iVar4 + 0xc) =
           *(byte *)(*piVar1 + iVar4 + 0xc) & 0xfe | (byte)uStack_28 & 1;
      memcpy((void *)(*piVar1 + iVar4 + 0xd),(undefined1 *)((int)register0x00002008 + -0x27),0x11);
      unaff_s0 = unaff_s0 + 1 & 0xff;
    }
_L0:
    ds_ias_zone_info_next(&bStack_34);
  } while( true );
}

