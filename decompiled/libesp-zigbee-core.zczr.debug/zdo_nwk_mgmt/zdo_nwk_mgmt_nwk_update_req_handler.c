/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_nwk_update_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_nwk_update_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  zdp_status_t zVar5;
  undefined3 extraout_var;
  int iVar6;
  void *pvVar7;
  channel_page_t channel_page;
  uint uStack_6c;
  channel_page_t iface_supported_1;
  channel_page_t iface_supported;
  code *pcStack_60;
  void *pvStack_5c;
  uint8_t uStack_58;
  undefined3 uStack_57;
  channel_page_t new_channel_page;
  uint16_t uStack_50;
  uint16_t uStack_4e;
  uint8_t uStack_4c;
  int8_t iStack_4b;
  int8_t iStack_4a;
  int8_t iStack_49;
  int8_t iStack_48;
  int8_t iStack_47;
  int8_t iStack_46;
  int8_t iStack_45;
  int8_t iStack_44;
  int8_t iStack_43;
  int8_t iStack_42;
  int8_t iStack_41;
  int8_t iStack_40;
  int8_t iStack_3f;
  int8_t iStack_3e;
  int8_t iStack_3d;
  int8_t iStack_3c;
  int8_t iStack_3b;
  int8_t iStack_3a;
  int8_t iStack_39;
  int8_t iStack_38;
  int8_t iStack_37;
  int8_t iStack_36;
  int8_t iStack_35;
  int8_t iStack_34;
  int8_t iStack_33;
  int8_t iStack_32;
  int8_t iStack_31;
  byte bStack_2d;
  undefined1 auStack_2c [3];
  uint8_t channel_num;
  zdp_nwk_mgmt_nwk_update_req_field_t req;
  
  _auStack_2c = 0;
  req.scan_channels = 0;
  req.scan_duration = '\0';
  req.scan_count = '\0';
  req.nwk_update_id = '\0';
  req._7_1_ = 0;
  bStack_2d = 0xff;
  if (packet == (zdo_packet_t *)0x0) {
    zVar5 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar5 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar5 = 0xfe;
  }
  else {
    uVar1 = packet->dst_addr;
    zVar5 = zdo_op_nwk_mgmt_nwk_update_req
                      (packet->payload,(zdp_nwk_mgmt_nwk_update_req_field_t *)auStack_2c,false);
    uVar3 = _auStack_2c;
    if (CONCAT31(extraout_var,zVar5) == 0) {
      channel_page.u32 = _auStack_2c & 0x7ffffff;
      uVar2 = req.scan_channels & 0xff;
      if (uVar2 == 0xfe) {
        iVar6 = core_globals_get();
        if ((*(int *)(iVar6 + 0xa30) == 0) ||
           (iVar6 = core_globals_get(), *(uint *)(iVar6 + 0xa30) == (uVar3 & 0x7ffffff))) {
          bVar4 = 0;
          for (uVar3 = uVar3 & 0x7ffffff; uVar3 != 0; uVar3 = uVar3 & uVar3 - 1) {
            bVar4 = bVar4 + 1;
          }
          if (bVar4 < 2) {
            bStack_2d = 0xff;
            channel_page_get_next_channel(channel_page,&bStack_2d);
            iface_supported_1.u32 = 0;
            iVar6 = nwk_mm_get_pib_attr(0,99,&iface_supported_1,4);
            if ((iVar6 == 0) &&
               (((iface_supported_1.u32 & 0x7ffffff) >> (bStack_2d & 0x1f) & 1) != 0)) {
              _uStack_58 = 1 << (bStack_2d & 0x1f) & 0x7ffffff;
              nwk_mm_set_pib_attr(0x61,&stack0xffffffa8);
              return 0xfe;
            }
            uVar3 = 0x80;
          }
          else {
            uVar3 = 0x80;
          }
        }
        else {
          uVar3 = 0x8d;
        }
      }
      else {
        if (uVar2 == 0xff) {
          iVar6 = aps_secur_is_centralized();
          if ((iVar6 != 0) && (req._4_2_ != 0)) {
            return 0xfe;
          }
          iVar6 = core_globals_get();
          *(channel_page_t *)(iVar6 + 8) = channel_page;
          iVar6 = core_globals_get();
          *(undefined2 *)(iVar6 + 0x9dc) = req._4_2_;
          return 0xfe;
        }
        if (uVar2 < 6) {
          if (uVar1 < 0xfff8) {
            bStack_2d = 0xff;
            uStack_6c = 0;
            nwk_mm_get_pib_attr(0,99,&uStack_6c);
            if ((uVar3 & 0x7ffffff) == (uStack_6c & 0x7ffffff & uVar3 & 0x7ffffff)) {
              pvVar7 = calloc(1,0x18);
              if (pvVar7 == (void *)0x0) {
                uVar3 = 0x8a;
              }
              else {
                uVar3 = zdo_packet_move(resp);
                uVar3 = uVar3 & 0xff;
                if (uVar3 == 0) {
                  iface_supported_1.u32 =
                       (uint)CONCAT21(iface_supported_1.u32._2_2_,(undefined1)req.scan_channels) <<
                       8;
                  iface_supported.u32 = _auStack_2c;
                  pcStack_60 = zdo_mgmt_ed_scan_handler;
                  uStack_58 = '\0';
                  uStack_57 = 0;
                  new_channel_page.u32 = 0;
                  uStack_50 = 0;
                  uStack_4e = 0;
                  uStack_4c = '\0';
                  iStack_4b = '\0';
                  iStack_4a = '\0';
                  iStack_49 = '\0';
                  iStack_48 = '\0';
                  iStack_47 = '\0';
                  iStack_46 = '\0';
                  iStack_45 = '\0';
                  iStack_44 = '\0';
                  iStack_43 = '\0';
                  iStack_42 = '\0';
                  iStack_41 = '\0';
                  iStack_40 = '\0';
                  iStack_3f = '\0';
                  iStack_3e = '\0';
                  iStack_3d = '\0';
                  iStack_3c = '\0';
                  iStack_3b = '\0';
                  iStack_3a = '\0';
                  iStack_39 = '\0';
                  iStack_38 = '\0';
                  iStack_37 = '\0';
                  iStack_36 = '\0';
                  iStack_35 = '\0';
                  iStack_34 = '\0';
                  iStack_33 = '\0';
                  iStack_32 = '\0';
                  iStack_31 = '\0';
                  pvStack_5c = pvVar7;
                  zmsg_add_footer(*(undefined4 *)((int)pvVar7 + 0x14),&stack0xffffffa8,0x28);
                  nwk_nlme_scan(&iface_supported_1);
                  uVar3 = ezb_err_to_zdp_status();
                  if (uVar3 == 0) {
                    return 0xfe;
                  }
                  mm_free(pvVar7);
                }
                else {
                  mm_free(pvVar7);
                }
                if (uVar3 == 0xfe) {
                  return 0xfe;
                }
              }
            }
            else {
              uVar3 = 0x86;
            }
          }
          else {
            uVar3 = 0x80;
          }
        }
        else {
          uVar3 = 0x80;
        }
      }
      new_channel_page.u32 = 0;
      uStack_50 = 0;
      uStack_4e = 0;
      uStack_4c = '\0';
      iStack_4b = '\0';
      iStack_4a = '\0';
      iStack_49 = '\0';
      iStack_48 = '\0';
      iStack_47 = '\0';
      iStack_46 = '\0';
      iStack_45 = '\0';
      iStack_44 = '\0';
      iStack_43 = '\0';
      iStack_42 = '\0';
      iStack_41 = '\0';
      iStack_40 = '\0';
      iStack_3f = '\0';
      iStack_3e = '\0';
      iStack_3d = '\0';
      iStack_3c = '\0';
      iStack_3b = '\0';
      iStack_3a = '\0';
      iStack_39 = '\0';
      iStack_38 = '\0';
      iStack_37 = '\0';
      iStack_36 = '\0';
      iStack_35 = '\0';
      iStack_34 = '\0';
      iStack_33 = '\0';
      iStack_32 = '\0';
      iStack_31 = '\0';
      _uStack_58 = uVar3 & 0xff;
      zVar5 = zdo_op_nwk_mgmt_nwk_update_notify
                        (resp->payload,(zdp_nwk_mgmt_nwk_update_notify_field_t *)&stack0xffffffa8,
                         true);
    }
    else {
      zVar5 = 0xfe;
    }
  }
  return zVar5;
}

