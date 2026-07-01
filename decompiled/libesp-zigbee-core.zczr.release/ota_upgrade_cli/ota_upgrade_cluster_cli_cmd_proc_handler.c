/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ota_upgrade_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  ushort uVar2;
  uint16_t uVar3;
  _Bool _Var4;
  ezb_zcl_status_t eVar5;
  int iVar6;
  undefined3 extraout_var;
  int iVar7;
  ezb_err_t eVar8;
  ota_upgrade_downloading_context_t *poVar9;
  uint uVar10;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  uint uVar11;
  ota_upgrade_upgrade_end_rsp_t *value;
  uint8_t *puVar12;
  uint32_t uVar13;
  uint32_t *puVar14;
  uint uVar15;
  uint32_t uVar16;
  short sVar17;
  uint16_t uStack_66;
  uint16_t uStack_64;
  uint16_t offset_1;
  uint16_t offset;
  undefined1 auStack_5e [2];
  ota_upgrade_upgrade_end_rsp_t payload;
  void *pvStack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  memset(auStack_48,0,0x28);
  iVar7 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar7 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar6 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar7 = iVar6,
     iVar6 != 0)) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 5) {
    _uStack_64 = (uint)offset_1 << 0x10;
    memset(&offset,0,0x18);
    poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
    _Var4 = ota_upgrade_download_stop_timer(poVar9);
    if ((CONCAT31(extraout_var_02,_Var4) == 0) || (*(poVar9->attr).upgrade_status != '\x01')) {
_L143:
      uVar11 = 0xfe;
    }
    else {
      uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint8_t *)&offset);
      if ((_offset & 0xff) == 0) {
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.manuf_code);
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.image_type);
        af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.file_version);
        af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.current_time);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint8_t *)&payload.upgrade_time)
        ;
        uVar15 = (uint)(byte)payload.upgrade_time;
        pvStack_4c = calloc(1,uVar15);
        if ((pvStack_4c != (void *)0x0) || (uVar11 = 0x89, uVar15 == 0)) {
          uVar3 = uStack_64;
          iVar7 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),_uStack_64 & 0xffff,uVar15,
                                  pvStack_4c);
          if ((iVar7 == 0) && (uVar15 != 0)) {
            sVar17 = -1;
          }
          else {
            sVar17 = uVar3 + (short)iVar7;
          }
          _uStack_64 = CONCAT22(offset_1,sVar17);
          goto _L0;
        }
      }
      else {
        if ((_offset & 0xff) == 0x97) {
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint32_t *)&payload);
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.file_version);
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,
                       (uint16_t *)&payload.current_time);
        }
_L0:
        uVar11 = 0x80;
        if ((_uStack_64 & 0xffff) <= uVar10) {
          if ((_offset & 0xff) == 0) {
            if (((*(poVar9->attr).manuf_code != payload.manuf_code) ||
                (*(poVar9->attr).image_type != payload.image_type)) ||
               ((poVar9->file).downloading_version != payload.file_version)) goto _L143;
            uVar10 = (poVar9->file).total_size;
            uVar15 = (uint)(byte)payload.upgrade_time + *(poVar9->attr).file_offset;
            puVar12 = (poVar9->attr).upgrade_status;
            if ((uVar10 == 0) || (uVar15 < uVar10)) {
              *puVar12 = '\x01';
              *(poVar9->attr).file_offset = uVar15;
              (poVar9->file).downloading_version = payload.file_version;
              (poVar9->file).total_size = uVar10;
              eVar5 = ota_upgrade_setup_image_block_request
                                ((zcl_packet_t *)auStack_48,poVar9,(zcl_packet_t *)arg);
              uVar11 = CONCAT31(extraout_var_04,eVar5);
            }
            else {
              *puVar12 = '\x02';
              puVar14 = (poVar9->attr).downloaded_file_version;
              if (puVar14 != (uint32_t *)0x0) {
                *puVar14 = (poVar9->file).downloading_version;
              }
              eVar5 = ota_upgrade_setup_upgrade_end_request
                                ((zcl_packet_t *)auStack_48,poVar9,(zcl_packet_t *)arg,'\0');
              uVar11 = CONCAT31(extraout_var_03,eVar5);
            }
            if ((uVar11 == 0) &&
               (zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\x01',&offset),
               *(poVar9->attr).upgrade_status == '\x02')) {
              zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\x03',&offset);
            }
          }
          else {
            uVar11 = 0x95;
            if ((_offset & 0xff) == 0x97) {
              uVar11 = 0x85;
            }
          }
        }
      }
    }
    if (pvStack_4c != (void *)0x0) {
      mm_free();
    }
joined_r0x00010a6e:
    if (uVar11 != 0) {
_L0:
      iVar7 = zcl_packet_setup_default_response(auStack_48,arg,uVar11);
_L0:
      if (iVar7 != 0) goto _L0;
    }
  }
  else {
    if (bVar1 < 6) {
      if (bVar1 != 0) {
        if (bVar1 != 2) goto _L0;
        _uStack_64 = (uint)offset_1 << 0x10;
        _offset = 0;
        payload.manuf_code = 0;
        payload.image_type = 0;
        payload.file_version = 0;
        payload.current_time = 0;
        poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
        uVar11 = 0x95;
        if (*(poVar9->attr).upgrade_status != '\0') goto _L0;
        uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint8_t *)&offset);
        if ((char)offset == '\0') {
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint16_t *)auStack_5e);
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.manuf_code);
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.file_version);
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.current_time);
        }
        uVar11 = 0x80;
        if (uVar10 < (_uStack_64 & 0xffff)) goto _L0;
        eVar5 = zcl_message_ota_upgrade_query_next_image
                          ((zcl_packet_t *)arg,(ota_upgrade_query_next_image_rsp_t *)&offset);
        uVar11 = CONCAT31(extraout_var_00,eVar5);
        if (uVar11 != 0) goto _L0;
        ota_upgrade_download_stop_timer(poVar9);
        uVar11 = _offset & 0xff;
        if (uVar11 != 0) {
          if ((uVar11 == 0x7e) || (uVar11 == 0x98)) {
            ota_upgrade_set_upgrade_status_normal(poVar9);
          }
          else {
_L0:
            uVar11 = 0xfe;
          }
          goto _L0;
        }
        if (((undefined1  [2])*(poVar9->attr).manuf_code != auStack_5e) ||
           (*(poVar9->attr).image_type != payload.manuf_code)) {
          uVar11 = 0x96;
          goto _L0;
        }
        puVar14 = (poVar9->attr).current_file_version;
        if (((puVar14 != (uint32_t *)0x0) && (*puVar14 == payload.file_version)) ||
           ((puVar14 = (poVar9->attr).downloaded_file_version, puVar14 != (uint32_t *)0x0 &&
            (*puVar14 == payload.file_version)))) goto _L0;
        *(poVar9->attr).upgrade_status = '\x01';
        *(poVar9->attr).file_offset = 0;
        (poVar9->file).downloading_version = payload.file_version;
        (poVar9->file).total_size = payload.current_time;
        zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\0',&offset);
        eVar5 = ota_upgrade_setup_image_block_request
                          ((zcl_packet_t *)auStack_48,poVar9,(zcl_packet_t *)arg);
        iVar7 = CONCAT31(extraout_var_01,eVar5);
        goto _L0;
      }
      _offset = 0xffff0000;
      payload.manuf_code = 0xffff;
      payload.image_type = 0;
      payload.file_version = 0xffffffff;
      uStack_66 = 0;
      poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
      uVar11 = 0x95;
      if (*(poVar9->attr).upgrade_status != '\0') goto _L0;
      uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24),0x95);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint8_t *)&offset);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint8_t *)((int)&offset + 1));
      uVar15 = _offset & 0xff;
      if (uVar15 == 3) {
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint16_t *)auStack_5e);
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,&payload.manuf_code);
        af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_66,&payload.file_version);
      }
      else {
        if (uVar15 == 2) {
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint16_t *)auStack_5e);
          value = &payload;
        }
        else {
          uVar11 = 0x81;
          if (uVar15 != 1) goto _L0;
          value = (ota_upgrade_upgrade_end_rsp_t *)auStack_5e;
        }
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,&value->manuf_code);
      }
      uVar11 = 0x80;
      if (uVar10 < uStack_66) goto _L0;
      uVar2 = *(ushort *)((int)arg + 0xc);
      if (uVar2 < 0xfff8) {
        uVar10 = nwk_get_short_address(0x80);
        if (uVar2 != uVar10) goto _L0;
      }
      else {
        uVar10 = _offset & 0xff;
        if (uVar10 == 2) {
_L0:
          uVar15 = payload._0_4_ & 0xffff;
          if (*(poVar9->attr).image_type != uVar15) {
            uVar10 = 0xffff;
            goto _L0;
          }
        }
        else {
          if (uVar10 == 3) {
            puVar14 = (poVar9->attr).current_file_version;
            uVar13 = 0xffffffff;
            if (puVar14 != (uint32_t *)0x0) {
              uVar13 = *puVar14;
            }
            puVar14 = (poVar9->attr).downloaded_file_version;
            uVar16 = 0xffffffff;
            if (puVar14 != (uint32_t *)0x0) {
              uVar16 = *puVar14;
            }
            if ((payload.file_version == uVar13) || (payload.file_version == uVar16)) goto _L0;
            goto _L0;
          }
          uVar15 = 1;
_L0:
          if (uVar15 != uVar10) goto _L0;
        }
        if (((undefined1  [2])*(poVar9->attr).manuf_code != auStack_5e) &&
           (auStack_5e != (undefined1  [2])0xffff)) {
_L0:
          uVar11 = 0x96;
          goto _L0;
        }
      }
      uVar10 = random_noncrypto_get_u32();
      if ((_offset >> 8 & 0xff) < uVar10 % 100) goto _L0;
      iVar7 = zcl_packet_setup_response_with_extension(auStack_48,arg,1,0);
      if (iVar7 == 0) {
        _uStack_64 = _uStack_64 & 0xffffff00;
        iVar7 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff9c);
        if (((iVar7 == 0) &&
            (eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,*(poVar9->attr).manuf_code), eVar8 == 0))
           && (eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,*(poVar9->attr).image_type), eVar8 == 0
              )) {
          puVar14 = (poVar9->attr).current_file_version;
          _uStack_64 = 0xffffffff;
          if (puVar14 != (uint32_t *)0x0) {
            _uStack_64 = *puVar14;
          }
          iVar7 = zmsg_append_bytes(rsp._32_4_,4,&stack0xffffff9c);
          if (iVar7 == 0) goto _L0;
        }
        iVar7 = 0x89;
      }
_L0:
      zcl_packet_free(auStack_48);
      goto _L0;
    }
    if (bVar1 != 7) {
_L0:
      uVar11 = 0x81;
      goto _L0;
    }
    _uStack_64 = (uint)offset_1 << 0x10;
    _offset = 0;
    payload.manuf_code = 0;
    payload.image_type = 0;
    payload.file_version = 0;
    payload.current_time = 0;
    poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
    _Var4 = ota_upgrade_download_stop_timer(poVar9);
    if ((CONCAT31(extraout_var,_Var4) == 0) || (*(poVar9->attr).upgrade_status != '\x02')) {
_L0:
      uVar11 = 0xfe;
      goto _L0;
    }
    uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&offset);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint16_t *)auStack_5e);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,(uint32_t *)&payload);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.file_version);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9c,&payload.current_time);
    uVar11 = 0x80;
    if (uVar10 < (_uStack_64 & 0xffff)) goto _L0;
    if ((((((uint)*(poVar9->attr).manuf_code != (_offset & 0xffff)) &&
          ((_offset & 0xffff) != 0xffff)) ||
         (((undefined1  [2])*(poVar9->attr).image_type != auStack_5e &&
          (auStack_5e != (undefined1  [2])0xffff)))) ||
        (((poVar9->file).downloading_version != payload._0_4_ && (payload._0_4_ != -1)))) ||
       ((payload.current_time != 0xffffffff && (payload.current_time < payload.file_version))))
    goto _L0;
    *(poVar9->attr).file_offset = 0;
    memset(&poVar9->file,0,8);
    if (payload.current_time != 0xffffffff) {
      eVar5 = zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\x04',&offset);
      iVar7 = CONCAT31(extraout_var_05,eVar5);
      if (iVar7 == 0x96) {
        ota_upgrade_set_upgrade_status_normal(poVar9);
      }
      else {
        if (iVar7 != 0x99) {
          if (iVar7 != 0) {
            ota_upgrade_set_upgrade_status_normal(poVar9);
            goto _L0;
          }
          *(poVar9->attr).upgrade_status = '\x04';
          zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\x05',&offset);
          ota_upgrade_set_upgrade_status_normal(poVar9);
          goto _L0;
        }
        *(poVar9->attr).upgrade_status = '\x05';
      }
      eVar5 = ota_upgrade_setup_upgrade_end_request
                        ((zcl_packet_t *)auStack_48,poVar9,(zcl_packet_t *)arg,eVar5);
      uVar11 = CONCAT31(extraout_var_06,eVar5);
      goto joined_r0x00010a6e;
    }
    *(poVar9->attr).upgrade_status = '\x03';
  }
_L0:
  ota_upgrade_packet_send((zcl_packet_t *)auStack_48);
  iVar7 = iVar6;
_L0:
  return (ezb_zcl_status_t)iVar7;
}

