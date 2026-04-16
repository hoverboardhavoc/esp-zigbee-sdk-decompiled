/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> convert_beacon_to_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_beacon_to_parent(nwk_potential_parent_t *parent,nwk_beacon_info_t *zigbee_beacon)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7 aVar4;
  anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7 aVar5;
  
  parent->update_id = zigbee_beacon->update_id;
  uVar1 = ((byte)zigbee_beacon->field_0x2 >> 2 & 1) << 0xe;
  aVar4 = parent->field_7;
  parent->field_7 =
       (anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7)((uint)aVar4 & 0xffffbfff | uVar1);
  uVar2 = (uint)((byte)zigbee_beacon->field_0x2 >> 7) << 0xf;
  parent->field_7 =
       (anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7)
       ((uint)aVar4 & 0xffff3fff | uVar1 | uVar2);
  uVar3 = ((byte)zigbee_beacon->field_0x1 & 3) << 0x10;
  aVar5 = (anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7)
          ((uint)aVar4 & 0xfffc3fff | uVar1 | uVar2 | uVar3);
  parent->field_7 = aVar5;
  if ((int)aVar5 << 2 < 0) {
    parent->field_7 =
         (anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7)
         ((uint)aVar4 & 0xfff03fff | uVar1 | uVar2 | uVar3 |
         (uint)((parent->addr).short_addr != 0) << 0x12);
  }
  else {
    parent->field_7 =
         (anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7)(parent->field_7 | 0xc0000);
  }
  parent->field_7 =
       (anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7)
       (((byte)zigbee_beacon->field_0x2 >> 3 & 0xf) << 0x14 | (uint)parent->field_7 & 0xff0fffff);
  return;
}

