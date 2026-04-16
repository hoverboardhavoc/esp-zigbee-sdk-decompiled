/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_view_scene_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_view_scene_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte bVar1;
  uint16_t *puVar2;
  ezb_zcl_status_t eVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint8_t *value;
  undefined1 auStack_44 [4];
  zcl_scene_table_entry_t entry;
  uint8_t status;
  uint16_t offset;
  
  entry.extension_field._2_2_ = 0;
  entry.extension_field._1_1_ = '\0';
  auStack_44[0] = false;
  auStack_44[1] = 0;
  auStack_44._2_2_ = 0;
  entry.is_used = false;
  entry._1_1_ = 0;
  entry.group_id = 0;
  entry.scene_id = '\0';
  entry._5_1_ = 0;
  entry.transition_time = 0;
  entry.scene_name[0] = '\0';
  entry.scene_name[1] = '\0';
  entry.scene_name[2] = '\0';
  entry.scene_name[3] = '\0';
  entry.scene_name[4] = '\0';
  entry.scene_name[5] = '\0';
  entry.scene_name[6] = '\0';
  entry.scene_name[7] = '\0';
  entry.scene_name[8] = '\0';
  entry.scene_name[9] = '\0';
  entry.scene_name[10] = '\0';
  entry.scene_name[0xb] = '\0';
  entry.scene_name[0xc] = '\0';
  entry.scene_name[0xd] = '\0';
  entry.scene_name[0xe] = '\0';
  entry.scene_name[0xf] = '\0';
  entry.scene_name[0x10] = '\0';
  entry.transition_time_100ms = '\0';
  entry._26_2_ = 0;
  uVar4 = zmsg_get_length(packet->payload);
  puVar2 = (uint16_t *)((int)&entry.extension_field + 2);
  af_read_le8(packet->payload,puVar2,(uint8_t *)((int)&entry.extension_field + 1));
  af_read_le16(packet->payload,puVar2,(uint16_t *)(auStack_44 + 2));
  af_read_le8(packet->payload,puVar2,&entry.is_used);
  if (entry.extension_field._1_1_ == '\0') {
    af_read_le16(packet->payload,puVar2,&entry.group_id);
    af_read_le8(packet->payload,puVar2,&entry.scene_id);
    if (0x11 < entry.scene_id) {
      eVar3 = 0x80;
      goto _L0;
    }
    af_read_bytes(packet->payload,puVar2,(ushort)entry.scene_id,&entry.field_0x5);
    while (entry.extension_field._2_2_ < uVar4) {
      puVar5 = (undefined4 *)calloc(1,0xc);
      if (puVar5 == (undefined4 *)0x0) {
        eVar3 = 0x89;
        goto _L0;
      }
      *puVar5 = entry._24_4_;
      puVar2 = (uint16_t *)((int)&entry.extension_field + 2);
      entry._24_4_ = puVar5;
      af_read_le16(packet->payload,puVar2,(uint16_t *)(puVar5 + 1));
      af_read_le8(packet->payload,puVar2,(uint8_t *)((int)puVar5 + 6));
      bVar1 = *(byte *)((int)puVar5 + 6);
      if (bVar1 != 0) {
        value = (uint8_t *)calloc(1,(uint)bVar1);
        puVar5[2] = value;
        if (value == (uint8_t *)0x0) {
          eVar3 = 0x89;
          goto _L0;
        }
        af_read_bytes(packet->payload,(uint16_t *)((int)&entry.extension_field + 2),(ushort)bVar1,
                      value);
      }
    }
  }
  if (uVar4 < entry.extension_field._2_2_) {
    eVar3 = 0x80;
  }
  else {
    eVar3 = zcl_message_scenes_view_scene_resp
                      (packet,entry.extension_field._1_1_,(zcl_scene_table_entry_t *)auStack_44);
  }
_L0:
  if (entry._24_4_ != 0) {
    scene_entry_free_scene_extension_field((zcl_scene_table_entry_t *)auStack_44);
  }
  eVar3 = zcl_packet_setup_default_response(rsp,packet,eVar3);
  return eVar3;
}

