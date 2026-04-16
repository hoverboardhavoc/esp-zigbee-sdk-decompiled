/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ota_upgrade_cluster_srv_cmd_proc_handler(void *arg)

{
  char cVar1;
  uint16_t uVar2;
  short sVar3;
  int iVar4;
  uint32_t val;
  ezb_zcl_status_t eVar5;
  uint uVar6;
  ota_upgrade_file_table_t *poVar7;
  undefined3 extraout_var;
  ezb_err_t eVar8;
  undefined4 uVar9;
  uint8_t *puVar10;
  uint uVar11;
  ota_upgrade_file_t *poVar12;
  uint32_t val_00;
  undefined2 uStack_76;
  uint16_t uStack_74;
  uint16_t offset;
  ota_upgrade_query_next_image_req_payload_t payload;
  ezb_zcl_ota_upgrade_server_progress_start_t start;
  byte bStack_4c;
  uint16_t uStack_4a;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  iVar4 = 1;
  memset(auStack_48,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar4 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar4 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar4 != 0))
  goto _L0;
  cVar1 = *(char *)((int)arg + 0x20);
  if (cVar1 == '\x03') {
    _uStack_74 = _uStack_74 & 0xffff0000;
    memset(&payload.hw_version,0,0x1c);
    uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint8_t *)&payload.hw_version);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint16_t *)&payload.field_0xe);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint16_t *)&start);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint32_t *)&start.query.manuf_code)
    ;
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,&start.query.file_version);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint8_t *)&start.query.hw_version);
    if ((payload._12_4_ & 1) != 0) {
      uVar2 = uStack_74;
      iVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),_uStack_74 & 0xffff,8,
                              (undefined1 *)((int)&start.query.hw_version + 1));
      if (iVar4 == 0) {
        sVar3 = -1;
      }
      else {
        sVar3 = uVar2 + (short)iVar4;
      }
      _uStack_74 = CONCAT22(offset,sVar3);
    }
    if ((payload._12_4_ & 2) != 0) {
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,&uStack_4a);
    }
    uVar9 = 0x80;
    if ((_uStack_74 & 0xffff) <= uVar6) {
      poVar12 = (ota_upgrade_file_t *)0x0;
      poVar7 = ota_upgrade_get_file_table(*(uint8_t *)((int)arg + 0x15));
      for (uVar6 = 0; (uVar6 & 0xff) < (uint)poVar7->size; uVar6 = uVar6 + 1) {
        poVar12 = poVar7->entry + uVar6;
        if ((((poVar12->header).manufacturer_code == payload._14_2_) &&
            ((uint)(poVar12->header).image_type == (start.query._0_4_ & 0xffff))) &&
           ((poVar12->header).file_version == start.query._4_4_)) {
          if ((payload._12_4_ & 1) == 0) break;
          if ((*(uint *)&(poVar12->optional).upgrade_file_destination.field_0 ==
               (start.policy.file_version << 0x18 | (uint)start.query._12_4_ >> 8)) &&
             (*(uint *)((int)&(poVar12->optional).upgrade_file_destination.field_0 + 4) ==
              ((uint)bStack_4c << 0x18 | start.policy.file_version >> 8))) goto _L0;
        }
      }
      if (poVar12 == (ota_upgrade_file_t *)0x0) {
        uVar9 = 0x98;
      }
      else {
_L0:
        zcl_message_ota_upgrade_server_progress
                  ((zcl_packet_t *)arg,'\x02',&payload.hw_version,(void *)0x0);
        uVar6 = (poVar12->header).total_image_size;
        if (start.query.file_version < uVar6) {
          if (uVar6 < (start.query._12_4_ & 0xff) + start.query.file_version) {
            start.query.hw_version._0_1_ = (char)uVar6 - (char)start.query.file_version;
          }
          uStack_76 = (ushort)uStack_76._1_1_ << 8;
          iVar4 = zmsg_append_bytes(rsp._32_4_,1,&uStack_76);
          if (iVar4 == 0) {
            eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,payload._14_2_);
            if (eVar8 == 0) {
              eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,start.query.short_address);
              if (((eVar8 == 0) &&
                  (eVar8 = zmsg_append_le32((zmsg_t *)rsp._32_4_,start.query._4_4_), eVar8 == 0)) &&
                 (eVar8 = zmsg_append_le32((zmsg_t *)rsp._32_4_,start.query.file_version),
                 eVar8 == 0)) {
                uStack_76 = CONCAT11(uStack_76._1_1_,(char)start.query.hw_version);
                iVar4 = zmsg_append_bytes(rsp._32_4_,1,&uStack_76);
                if (iVar4 == 0) {
                  uVar6 = start.query._12_4_ & 0xff;
                  puVar10 = poVar12->data + start.query.file_version;
                  goto _L0;
                }
              }
            }
          }
        }
        else {
          uStack_76 = CONCAT11(uStack_76._1_1_,0x98);
          puVar10 = (uint8_t *)&uStack_76;
          uVar6 = 1;
_L0:
          iVar4 = zmsg_append_bytes(rsp._32_4_,uVar6,puVar10);
          if (iVar4 == 0) {
            uVar9 = 5;
            goto _L0;
          }
        }
        uVar9 = 0x89;
      }
    }
    goto _L0;
  }
  if (cVar1 == '\x06') {
    uStack_76 = 0;
    payload.hw_version = 0;
    payload._14_2_ = 0;
    start.query.short_address = 0;
    start.query.ep_id = '\0';
    start.query._3_1_ = 0;
    start.query.manuf_code = 0;
    start.query.image_type = 0;
    uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint8_t *)&payload.hw_version);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t *)&payload.field_0xe);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t *)&start);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint32_t *)&start.query.manuf_code);
    uVar9 = 0x80;
    if (uVar6 < uStack_76) goto _L0;
    _uStack_74 = 0;
    zcl_message_ota_upgrade_server_progress
              ((zcl_packet_t *)arg,'\x05',&payload.hw_version,&stack0xffffff8c);
    if ((char)payload.hw_version == '\0') {
      uVar11 = _uStack_74 & 0xffff;
      uVar6 = _uStack_74 >> 0x10;
      eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,payload._14_2_);
      if (eVar8 == 0) {
        eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,start.query.short_address);
        if (((eVar8 == 0) &&
            (eVar8 = zmsg_append_le32((zmsg_t *)rsp._32_4_,start.query._4_4_), eVar8 == 0)) &&
           (eVar8 = zmsg_append_le32((zmsg_t *)rsp._32_4_,uVar11), eVar8 == 0)) {
          zmsg_append_le32((zmsg_t *)rsp._32_4_,uVar6);
        }
      }
      if ((char)payload.hw_version == '\0') {
        uVar9 = 7;
        goto _L0;
      }
    }
    uVar9 = 0;
_L0:
    iVar4 = zcl_packet_setup_default_response(auStack_48,arg,uVar9);
  }
  else {
    if (cVar1 != '\x01') {
      uVar9 = 0x81;
      goto _L0;
    }
    uStack_76 = 0;
    _uStack_74 = 0;
    payload.fc = '\0';
    payload._1_1_ = 0;
    payload.manuf_code = 0;
    payload.image_type = 0;
    payload._6_2_ = 0;
    payload.file_version = 0;
    uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint8_t *)&stack0xffffff8c);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,&offset);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t *)&payload);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint32_t *)&payload.image_type);
    if ((_uStack_74 & 1) != 0) {
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t *)&payload.file_version);
    }
    if (uVar6 < uStack_76) {
      uVar9 = 0x80;
      goto _L0;
    }
    poVar7 = ota_upgrade_get_file_table(*(uint8_t *)((int)arg + 0x15));
    if (poVar7 == (ota_upgrade_file_table_t *)0x0) {
_L0:
      payload.hw_version._0_1_ = 0x98;
      iVar4 = zmsg_append_bytes(rsp._32_4_,1,&payload.hw_version);
_L0:
      if (iVar4 != 0) {
_L0:
        uVar9 = 0x89;
        goto _L0;
      }
    }
    else {
      iVar4 = 1;
      for (uVar6 = 0; uVar9 = payload._0_4_, uVar6 < poVar7->size; uVar6 = uVar6 + 1 & 0xff) {
        poVar12 = poVar7->entry;
        if ((poVar12[uVar6].header.manufacturer_code == offset) &&
           ((uint)poVar12[uVar6].header.image_type == (payload._0_4_ & 0xffff))) {
          if ((((_uStack_74 & 1) == 0) || ((poVar12[uVar6].header.hdr_fc & 4) == 0)) ||
             ((uVar11 = *(uint *)((int)&poVar12[uVar6].optional.upgrade_file_destination.field_0 + 7
                                 ), (uVar11 >> 8 & 0xffff) <= (payload.file_version & 0xffff) &&
              ((payload.file_version & 0xffff) <=
               ((uint)*(byte *)((int)&poVar12[uVar6].optional.maximum_hardware_version + 1) << 8 |
               uVar11 >> 0x18))))) {
            start.query.ep_id = payload.fc;
            start.query._3_1_ = payload._1_1_;
            start.query.short_address = offset;
            start.query.file_version =
                 CONCAT22(start.query.file_version._2_2_,(undefined2)payload.file_version);
            payload._14_1_ = *(undefined1 *)((int)arg + 0x14);
            payload.hw_version = *(uint16_t *)((int)arg + 2);
            start.query.manuf_code = payload.image_type;
            start.query.image_type = payload._6_2_;
            start.query._12_4_ = poVar12[uVar6].header.file_version;
            payload._0_4_ = uVar9;
            eVar5 = zcl_message_ota_upgrade_server_progress
                              ((zcl_packet_t *)arg,'\0',&payload.hw_version,(void *)0x0);
            iVar4 = CONCAT31(extraout_var,eVar5);
            if (iVar4 == 0) {
              val = poVar12[uVar6].header.file_version;
              val_00 = poVar12[uVar6].header.total_image_size;
            }
            else {
              if (iVar4 != 0xfe) goto _L0;
              val = 0;
              val_00 = 0;
            }
            if (val_00 == 0) goto _L0;
            payload._12_4_ = payload._12_4_ & 0xffffff00;
            iVar4 = zmsg_append_bytes(rsp._32_4_,1,&payload.hw_version);
            if (iVar4 != 0) goto _L0;
            eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,offset);
            if (eVar8 != 0) goto _L0;
            eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,payload._0_2_);
            if ((eVar8 != 0) || (eVar8 = zmsg_append_le32((zmsg_t *)rsp._32_4_,val), eVar8 != 0))
            goto _L0;
            iVar4 = zmsg_append_le32((zmsg_t *)rsp._32_4_,val_00);
            goto _L0;
          }
        }
_L0:
      }
      if (iVar4 != 0x7e) goto _L0;
      payload.hw_version._0_1_ = 0x7e;
      iVar4 = zmsg_append_bytes(rsp._32_4_,1,&payload.hw_version);
      uVar9 = 0x7e;
      if (iVar4 != 0) goto _L0;
    }
    uVar9 = 2;
_L0:
    iVar4 = zcl_packet_setup_response_with_extension(auStack_48,arg,uVar9,0,1);
  }
  if (iVar4 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
_L0:
  return (ezb_zcl_status_t)iVar4;
}

