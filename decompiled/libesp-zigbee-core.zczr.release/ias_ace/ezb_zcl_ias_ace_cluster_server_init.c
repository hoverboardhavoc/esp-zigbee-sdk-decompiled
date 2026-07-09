/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ias_ace_cluster_server_init(uint param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 auStack_7c [20];
  byte bStack_68;
  undefined1 uStack_67;
  undefined2 uStack_66;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_5b [17];
  short sStack_4a;
  char cStack_48;
  byte abStack_44 [30];
  short sStack_26;
  char cStack_24;
  
  memcpy(auStack_7c,&_LANCHOR0,0x14);
  iVar2 = zcl_get_attr_desc(param_1,0x501,1,0xeff0,0x131b);
  if (iVar2 == 0) goto _L0;
  if (*(byte **)(iVar2 + 8) == (byte *)0x0) goto _L0;
  bVar1 = **(byte **)(iVar2 + 8);
  uVar8 = (uint)bVar1;
  if (uVar8 == 0) goto _L0;
  iVar2 = zcl_get_attr_desc(param_1,0x501,1,0xeff1,0x131b);
  if (iVar2 == 0) goto _L0;
  puVar3 = (undefined4 *)calloc(1,8);
  if (puVar3 == (undefined4 *)0x0) goto _L0;
  *(byte *)(puVar3 + 1) = bVar1;
  pvVar4 = calloc(uVar8,0x1e);
  *puVar3 = pvVar4;
  if (pvVar4 == (void *)0x0) goto _L0;
  iVar6 = 0;
  do {
    *(undefined2 *)((int)pvVar4 + 2) = 0xffff;
    *(undefined2 *)((int)pvVar4 + 4) = 0xffff;
    *(undefined2 *)((int)pvVar4 + 6) = 0xffff;
    *(undefined2 *)((int)pvVar4 + 8) = 0xffff;
    *(undefined2 *)((int)pvVar4 + 10) = 0xffff;
    iVar6 = iVar6 + 1;
    pvVar4 = (void *)((int)pvVar4 + 0x1e);
  } while (iVar6 < (int)uVar8);
  *(char *)((int)puVar3 + 5) = (char)param_1;
  *(undefined4 **)(iVar2 + 8) = puVar3;
  while (piVar5 = (int *)ezb_zcl_ias_ace_get_zone_table(param_1), piVar5 == (int *)0x0) {
_L0:
    __assert_func(0,0,0,0);
_L0:
    log_write(1,"ZCL_IAS_ACE","Zone table size is zero");
  }
  sStack_4a = 0;
  cStack_48 = '\0';
  uVar8 = 0;
  ds_ias_zone_info_itor_read(&bStack_68);
_L0:
  if (cStack_48 != '\0') goto _L0;
  if (bStack_68 != param_1) goto _L0;
  if (uVar8 < *(byte *)(piVar5 + 1)) goto _L0;
  sStack_26 = 0;
  cStack_24 = '\0';
  while( true ) {
    ds_ias_zone_info_itor_read(abStack_44);
    if (cStack_24 != '\0') break;
    if (abStack_44[0] == param_1) {
      ds_internal_remove_entry(0xd,abStack_44);
    }
    else {
      sStack_26 = sStack_26 + 1;
    }
  }
  piVar5 = (int *)ezb_zcl_ias_ace_get_zone_table(param_1);
  for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(piVar5 + 1); iVar2 = iVar2 + 1) {
    if (*(short *)(*piVar5 + iVar2 * 0x1e + 2) == -1) break;
    zone_table_store_zone_isra_0(param_1);
  }
_L0:
  iVar2 = zcl_cluster_template_add(auStack_7c);
  if (iVar2 == 0) {
    return;
  }
  goto _L0;
_L0:
  iVar2 = uVar8 * 0x1e;
  uVar8 = uVar8 + 1 & 0xff;
  puVar7 = (undefined1 *)(*piVar5 + iVar2);
  *puVar7 = uStack_67;
  *(undefined2 *)(puVar7 + 2) = uStack_66;
  *(short *)(puVar7 + 4) = (short)uStack_64;
  *(short *)(puVar7 + 8) = (short)uStack_60;
  *(short *)(puVar7 + 6) = (short)((uint)uStack_64 >> 0x10);
  *(short *)(puVar7 + 10) = (short)((uint)uStack_60 >> 0x10);
  puVar7[0xc] = puVar7[0xc] & 0xfe | (byte)uStack_5c & 1;
  memcpy(puVar7 + 0xd,(undefined1 *)((int)register0x00002008 + -0x5b),0x11);
  if (cStack_48 == '\0') {
_L0:
    sStack_4a = sStack_4a + 1;
    ds_ias_zone_info_itor_read(&bStack_68);
  }
  goto _L0;
}

