/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00011302) */
/* WARNING: Removing unreachable block (ram,0x00011316) */
/* WARNING: Removing unreachable block (ram,0x0001131e) */
/* WARNING: Removing unreachable block (ram,0x00011330) */
/* WARNING: Unknown calling convention */

void ezb_zcl_ias_ace_cluster_server_init(uint8_t ep_id)

{
  byte bVar1;
  undefined3 in_register_00002029;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 auStack_7c [4];
  zcl_cluster_template_t template;
  ds_ias_zone_info_iterator_t itor;
  ds_ias_zone_info_iterator_t itor_1;
  
  uVar2 = CONCAT31(in_register_00002029,ep_id);
  memcpy(auStack_7c,&_LANCHOR0,0x14);
  iVar3 = zcl_get_attr_desc(uVar2,0x501,1,0xeff0,0x131b);
  if (iVar3 == 0) goto _L0;
  if (*(byte **)(iVar3 + 8) == (byte *)0x0) goto _L0;
  bVar1 = **(byte **)(iVar3 + 8);
  uVar9 = (uint)bVar1;
  if (uVar9 == 0) goto _L0;
  iVar3 = zcl_get_attr_desc(uVar2,0x501,1,0xeff1,0x131b);
  if (iVar3 == 0) goto _L0;
  puVar4 = (undefined4 *)calloc(1,8);
  if (puVar4 == (undefined4 *)0x0) goto _L0;
  *(byte *)(puVar4 + 1) = bVar1;
  pvVar5 = calloc(uVar9,0x1e);
  *puVar4 = pvVar5;
  if (pvVar5 == (void *)0x0) goto _L0;
  iVar7 = 0;
  do {
    *(undefined2 *)((int)pvVar5 + 2) = 0xffff;
    *(undefined2 *)((int)pvVar5 + 4) = 0xffff;
    *(undefined2 *)((int)pvVar5 + 6) = 0xffff;
    *(undefined2 *)((int)pvVar5 + 8) = 0xffff;
    *(undefined2 *)((int)pvVar5 + 10) = 0xffff;
    iVar7 = iVar7 + 1;
    pvVar5 = (void *)((int)pvVar5 + 0x1e);
  } while (iVar7 < (int)uVar9);
  *(uint8_t *)((int)puVar4 + 5) = ep_id;
  *(undefined4 **)(iVar3 + 8) = puVar4;
  do {
    piVar6 = (int *)ezb_zcl_ias_ace_get_zone_table(ep_id);
    if (piVar6 != (int *)0x0) {
      itor.data.zone_label[0xd] = '\0';
      itor.data.zone_label[0xe] = '\0';
      itor.data.zone_label[0xf] = '\0';
      uVar9 = 0;
      ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)&template.field_5);
_L0:
      if (itor.data.zone_label[0xf] == '\0') {
        if ((byte)template.field_5._0_1_ == uVar2) break;
        goto _L0;
      }
      iVar3 = zcl_cluster_template_add(auStack_7c);
      if (iVar3 == 0) {
        return;
      }
    }
_L0:
    __assert_func(0,0,0,0);
_L0:
    log_write(1,"ZCL_IAS_ACE","Zone table size is zero");
  } while( true );
  if (*(byte *)(piVar6 + 1) <= uVar9) {
    do {
      do {
        ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)&itor.is_done);
      } while (itor.is_done != uVar2);
      ds_internal_remove_entry(0xd,&itor.is_done);
    } while( true );
  }
  iVar3 = uVar9 * 0x1e;
  uVar9 = uVar9 + 1 & 0xff;
  puVar8 = (undefined1 *)(*piVar6 + iVar3);
  *puVar8 = template.field_5._1_1_;
  *(undefined2 *)(puVar8 + 2) = template.field_5._2_2_;
  *(short *)(puVar8 + 4) = (short)itor.data._0_4_;
  *(short *)(puVar8 + 8) = (short)itor.data.zone_address.field_0.u64._0_4_;
  *(uint16_t *)(puVar8 + 6) = SUB42(itor.data._0_4_,2);
  *(short *)(puVar8 + 10) = (short)((uint)itor.data.zone_address.field_0._0_4_ >> 0x10);
  puVar8[0xc] = puVar8[0xc] & 0xfe | (byte)itor.data.zone_address.field_0.u64._4_4_ & 1;
  memcpy(puVar8 + 0xd,(void *)((int)&itor.data.zone_address.field_0 + 5),0x11);
  if (itor.data.zone_label[0xf] == '\0') {
_L0:
    itor.data.zone_label._13_2_ = itor.data.zone_label._13_2_ + 1;
    ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)&template.field_5);
  }
  goto _L0;
}

