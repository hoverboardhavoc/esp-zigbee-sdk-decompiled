/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  undefined3 extraout_var_00;
  uint uVar10;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar11;
  ota_upgrade_upgrade_end_rsp_t *value;
  uint8_t *puVar12;
  uint32_t uVar13;
  uint32_t *puVar14;
  uint uVar15;
  uint32_t uVar16;
  short sVar17;
  uint16_t uStack_6e;
  uint16_t uStack_6c;
  uint16_t offset_1;
  uint16_t offset;
  zcl_packet_cnf_ctx_t cnf_ctx;
  ota_upgrade_upgrade_end_rsp_t payload;
  void *pvStack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  memset(auStack_48,0,0x28);
  _offset = (code *)0x0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  iVar7 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar7 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar6 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar7 = iVar6,
     iVar6 != 0)) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 5) {
    _uStack_6c = (uint)offset_1 << 0x10;
    memset(&cnf_ctx.user_ctx,0,0x18);
    poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
    _Var4 = ota_upgrade_downloading_stop_rsp_timeout(poVar9,*(uint8_t *)((int)arg + 0x1e));
    if ((CONCAT31(extraout_var_03,_Var4) == 0) || (*(poVar9->attr).upgrade_status != '\x01')) {
_L151:
      uVar11 = 0xfe;
    }
    else {
      uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,(uint8_t *)&cnf_ctx.user_ctx);
      if (((uint)cnf_ctx.user_ctx & 0xff) == 0) {
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.manuf_code);
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.image_type);
        af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.file_version);
        af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.current_time);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,(uint8_t *)&payload.upgrade_time)
        ;
        uVar15 = (uint)(byte)payload.upgrade_time;
        pvStack_4c = calloc(1,uVar15);
        if ((pvStack_4c != (void *)0x0) || (uVar11 = 0x89, uVar15 == 0)) {
          uVar3 = uStack_6c;
          iVar7 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),_uStack_6c & 0xffff,uVar15,
                                  pvStack_4c);
          if ((iVar7 == 0) && (uVar15 != 0)) {
            sVar17 = -1;
          }
          else {
            sVar17 = uVar3 + (short)iVar7;
          }
          _uStack_6c = CONCAT22(offset_1,sVar17);
          goto _L0;
        }
      }
      else {
        if (((uint)cnf_ctx.user_ctx & 0xff) == 0x97) {
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,(uint32_t *)&payload);
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.file_version);
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,
                       (uint16_t *)&payload.current_time);
        }
_L0:
        uVar11 = 0x80;
        if ((_uStack_6c & 0xffff) <= uVar10) {
          if (((uint)cnf_ctx.user_ctx & 0xff) == 0) {
            if (((*(poVar9->attr).manuf_code != payload.manuf_code) ||
                (*(poVar9->attr).image_type != payload.image_type)) ||
               ((poVar9->file).downloading_version != payload.file_version)) goto _L151;
            uVar10 = (poVar9->file).total_size;
            uVar15 = (uint)(byte)payload.upgrade_time + *(poVar9->attr).file_offset;
            puVar12 = (poVar9->attr).upgrade_status;
            if ((uVar10 == 0) || (uVar15 < uVar10)) {
              *puVar12 = '\x01';
              *(poVar9->attr).file_offset = uVar15;
              (poVar9->file).downloading_version = payload.file_version;
              (poVar9->file).total_size = uVar10;
              eVar5 = ota_upgrade_setup_image_block_request
                                ((zcl_packet_t *)auStack_48,(zcl_packet_t *)arg,poVar9);
              uVar11 = CONCAT31(extraout_var_05,eVar5);
            }
            else {
              *puVar12 = '\x02';
              puVar14 = (poVar9->attr).downloaded_file_version;
              if (puVar14 != (uint32_t *)0x0) {
                *puVar14 = (poVar9->file).downloading_version;
              }
              eVar5 = ota_upgrade_setup_upgrade_end_request
                                ((zcl_packet_t *)auStack_48,(zcl_packet_t *)arg,poVar9,'\0');
              uVar11 = CONCAT31(extraout_var_04,eVar5);
            }
            if (uVar11 == 0) {
              _offset = ota_upgrade_data_confirm_handler;
              cnf_ctx.cb = (ezb_af_user_cnf_callback_t)poVar9;
              zcl_message_ota_upgrade_downloading_progress
                        ((zcl_packet_t *)arg,'\x01',&cnf_ctx.user_ctx);
              if (*(poVar9->attr).upgrade_status == '\x02') {
                zcl_message_ota_upgrade_downloading_progress
                          ((zcl_packet_t *)arg,'\x03',&cnf_ctx.user_ctx);
              }
            }
          }
          else {
            uVar11 = 0x95;
            if (((uint)cnf_ctx.user_ctx & 0xff) == 0x97) {
              uVar11 = 0x85;
            }
          }
        }
      }
    }
    if (pvStack_4c != (void *)0x0) {
      mm_free();
    }
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
        _uStack_6c = (uint)offset_1 << 0x10;
        cnf_ctx.user_ctx = (void *)0x0;
        payload.manuf_code = 0;
        payload.image_type = 0;
        payload.file_version = 0;
        payload.current_time = 0;
        poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
        _Var4 = ota_upgrade_downloading_stop_rsp_timeout(poVar9,*(uint8_t *)((int)arg + 0x1e));
        if (CONCAT31(extraout_var_00,_Var4) == 0) goto _L145;
        uVar11 = 0x95;
        if (*(poVar9->attr).upgrade_status != '\0') goto _L0;
        uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,(uint8_t *)&cnf_ctx.user_ctx);
        if ((char)cnf_ctx.user_ctx == '\0') {
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,
                       (uint16_t *)((int)&cnf_ctx.user_ctx + 2));
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.manuf_code);
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.file_version);
          af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.current_time);
        }
        uVar11 = 0x80;
        if (uVar10 < (_uStack_6c & 0xffff)) goto _L0;
        eVar5 = zcl_message_ota_upgrade_query_next_image
                          ((zcl_packet_t *)arg,
                           (ota_upgrade_query_next_image_rsp_t *)&cnf_ctx.user_ctx);
        uVar11 = CONCAT31(extraout_var_01,eVar5);
        if (uVar11 != 0) goto _L0;
        uVar11 = (uint)cnf_ctx.user_ctx & 0xff;
        if (uVar11 != 0) {
          if ((uVar11 == 0x7e) || (uVar11 == 0x98)) {
            ota_upgrade_set_upgrade_status_normal(poVar9);
          }
          else {
_L145:
            uVar11 = 0xfe;
          }
          goto _L0;
        }
        if ((*(poVar9->attr).manuf_code != cnf_ctx.user_ctx._2_2_) ||
           (*(poVar9->attr).image_type != payload.manuf_code)) {
          uVar11 = 0x96;
          goto _L0;
        }
        puVar14 = (poVar9->attr).current_file_version;
        if (((puVar14 != (uint32_t *)0x0) && (*puVar14 == payload.file_version)) ||
           ((puVar14 = (poVar9->attr).downloaded_file_version, puVar14 != (uint32_t *)0x0 &&
            (*puVar14 == payload.file_version)))) goto _L145;
        *(poVar9->attr).upgrade_status = '\x01';
        *(poVar9->attr).file_offset = 0;
        (poVar9->file).downloading_version = payload.file_version;
        (poVar9->file).total_size = payload.current_time;
        zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\0',&cnf_ctx.user_ctx);
        _offset = ota_upgrade_data_confirm_handler;
        cnf_ctx.cb = (ezb_af_user_cnf_callback_t)poVar9;
        eVar5 = ota_upgrade_setup_image_block_request
                          ((zcl_packet_t *)auStack_48,(zcl_packet_t *)arg,poVar9);
        iVar7 = CONCAT31(extraout_var_02,eVar5);
        goto _L0;
      }
      cnf_ctx.user_ctx = (void *)0xffff0000;
      payload.manuf_code = 0xffff;
      payload.image_type = 0;
      payload.file_version = 0xffffffff;
      uStack_6e = 0;
      poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
      uVar11 = 0x95;
      if (*(poVar9->attr).upgrade_status != '\0') goto _L0;
      uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24),0x95);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,(uint8_t *)&cnf_ctx.user_ctx);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,(uint8_t *)((int)&cnf_ctx.user_ctx + 1));
      uVar15 = (uint)cnf_ctx.user_ctx & 0xff;
      if (uVar15 == 3) {
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,
                     (uint16_t *)((int)&cnf_ctx.user_ctx + 2));
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,&payload.manuf_code);
        af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,&payload.file_version);
      }
      else {
        if (uVar15 == 2) {
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,
                       (uint16_t *)((int)&cnf_ctx.user_ctx + 2));
          value = &payload;
        }
        else {
          uVar11 = 0x81;
          if (uVar15 != 1) goto _L0;
          value = (ota_upgrade_upgrade_end_rsp_t *)((int)&cnf_ctx.user_ctx + 2);
        }
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,&value->manuf_code);
      }
      uVar11 = 0x80;
      if (uVar10 < uStack_6e) goto _L0;
      uVar2 = *(ushort *)((int)arg + 0xc);
      if (uVar2 < 0xfff8) {
        uVar10 = nwk_get_short_address(0x80);
        if (uVar2 != uVar10) goto _L0;
      }
      else {
        uVar10 = (uint)cnf_ctx.user_ctx & 0xff;
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
        if ((*(poVar9->attr).manuf_code != cnf_ctx.user_ctx._2_2_) &&
           (cnf_ctx.user_ctx._2_2_ != 0xffff)) {
_L0:
          uVar11 = 0x96;
          goto _L0;
        }
      }
      uVar10 = random_noncrypto_get_u32();
      if (((uint)cnf_ctx.user_ctx >> 8 & 0xff) < uVar10 % 100) goto _L0;
      _offset = ota_upgrade_data_confirm_handler;
      cnf_ctx.cb = (ezb_af_user_cnf_callback_t)poVar9;
      iVar7 = zcl_packet_setup_response_with_extension(auStack_48,arg,1,0);
      if (iVar7 == 0) {
        _uStack_6c = _uStack_6c & 0xffffff00;
        iVar7 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff94);
        if (((iVar7 == 0) &&
            (eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,*(poVar9->attr).manuf_code), eVar8 == 0))
           && (eVar8 = zmsg_append_le16((zmsg_t *)rsp._32_4_,*(poVar9->attr).image_type), eVar8 == 0
              )) {
          puVar14 = (poVar9->attr).current_file_version;
          _uStack_6c = 0xffffffff;
          if (puVar14 != (uint32_t *)0x0) {
            _uStack_6c = *puVar14;
          }
          iVar7 = zmsg_append_bytes(rsp._32_4_,4,&stack0xffffff94);
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
    _uStack_6c = (uint)offset_1 << 0x10;
    cnf_ctx.user_ctx = (void *)0x0;
    payload.manuf_code = 0;
    payload.image_type = 0;
    payload.file_version = 0;
    payload.current_time = 0;
    poVar9 = ota_upgrade_downloading_context_get(*(uint8_t *)((int)arg + 0x15));
    _Var4 = ota_upgrade_downloading_stop_rsp_timeout(poVar9,*(uint8_t *)((int)arg + 0x1e));
    if ((CONCAT31(extraout_var,_Var4) == 0) || (*(poVar9->attr).upgrade_status != '\x02')) {
_L0:
      uVar11 = 0xfe;
      goto _L0;
    }
    uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,(uint16_t *)&cnf_ctx.user_ctx);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,
                 (uint16_t *)((int)&cnf_ctx.user_ctx + 2));
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,(uint32_t *)&payload);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.file_version);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff94,&payload.current_time);
    uVar11 = 0x80;
    if (uVar10 < (_uStack_6c & 0xffff)) goto _L0;
    if ((((((uint)*(poVar9->attr).manuf_code != ((uint)cnf_ctx.user_ctx & 0xffff)) &&
          (((uint)cnf_ctx.user_ctx & 0xffff) != 0xffff)) ||
         ((*(poVar9->attr).image_type != cnf_ctx.user_ctx._2_2_ &&
          (cnf_ctx.user_ctx._2_2_ != 0xffff)))) ||
        (((poVar9->file).downloading_version != payload._0_4_ && (payload._0_4_ != -1)))) ||
       ((payload.current_time != 0xffffffff && (payload.current_time < payload.file_version))))
    goto _L0;
    *(poVar9->attr).file_offset = 0;
    memset(&poVar9->file,0,8);
    if (payload.current_time == 0xffffffff) {
      *(poVar9->attr).upgrade_status = '\x03';
    }
    else {
      eVar5 = zcl_message_ota_upgrade_downloading_progress
                        ((zcl_packet_t *)arg,'\x04',&cnf_ctx.user_ctx);
      iVar7 = CONCAT31(extraout_var_06,eVar5);
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
          zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)arg,'\x05',&cnf_ctx.user_ctx)
          ;
          ota_upgrade_set_upgrade_status_normal(poVar9);
          goto _L0;
        }
        *(poVar9->attr).upgrade_status = '\x05';
      }
      eVar5 = ota_upgrade_setup_upgrade_end_request
                        ((zcl_packet_t *)auStack_48,(zcl_packet_t *)arg,poVar9,eVar5);
      uVar11 = CONCAT31(extraout_var_07,eVar5);
      if (uVar11 != 0) goto _L0;
      _offset = ota_upgrade_data_confirm_handler;
      cnf_ctx.cb = (ezb_af_user_cnf_callback_t)poVar9;
    }
  }
_L0:
  zcl_packet_send(auStack_48,&offset);
  iVar7 = iVar6;
_L0:
  return (ezb_zcl_status_t)iVar7;
}

