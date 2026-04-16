/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: itor */
/* WARNING: Unknown calling convention */

void zone_table_restore(uint8_t ep_id)

{
  bool bVar1;
  uint unaff_s0;
  undefined3 in_register_00002029;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_34 [4];
  ds_ias_zone_info_iterator_t itor;
  
  piVar2 = (int *)ezb_zcl_ias_ace_get_zone_table(ep_id);
  if (piVar2 == (int *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xab,"zone_table_restore",
                  "zone_table");
    goto _L0;
  }
  itor.data.zone_label[0xd] = '\0';
  itor.data.zone_label[0xe] = '\0';
  itor.data.zone_label[0xf] = '\0';
  ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)auStack_34);
  unaff_s0 = 0;
  do {
    if (itor.data.zone_label[0xf] != '\0') {
      bVar1 = false;
_L0:
      if (bVar1) {
        zone_table_refresh_stored_zones(ep_id);
      }
      return;
    }
    if ((uint)auStack_34[0] == CONCAT31(in_register_00002029,ep_id)) {
      if (*(byte *)(piVar2 + 1) <= unaff_s0) {
        bVar1 = true;
        goto _L0;
      }
      iVar4 = unaff_s0 * 0x1e;
      *(uint8_t *)(*piVar2 + iVar4) = auStack_34[1];
      *(undefined2 *)(*piVar2 + iVar4 + 2) = auStack_34._2_2_;
      iVar3 = *piVar2 + iVar4;
      *(short *)(iVar3 + 4) = (short)itor.data._0_4_;
      *(uint16_t *)(iVar3 + 6) = SUB42(itor.data._0_4_,2);
      *(short *)(iVar3 + 8) = (short)itor.data.zone_address.field_0.u64._0_4_;
      *(short *)(iVar3 + 10) = (short)((uint)itor.data.zone_address.field_0._0_4_ >> 0x10);
      *(byte *)(*piVar2 + iVar4 + 0xc) =
           *(byte *)(*piVar2 + iVar4 + 0xc) & 0xfe |
           (byte)itor.data.zone_address.field_0.u64._4_4_ & 1;
      memcpy((void *)(*piVar2 + iVar4 + 0xd),(void *)((int)&itor.data.zone_address.field_0 + 5),0x11
            );
      unaff_s0 = unaff_s0 + 1 & 0xff;
    }
_L0:
    ds_ias_zone_info_next((ds_ias_zone_info_iterator_t *)auStack_34);
  } while( true );
}

