/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  zdp_status_t zVar2;
  undefined3 extraout_var;
  int iVar3;
  byte bVar4;
  undefined1 uVar5;
  uint uVar6;
  channel_page_t channel_page;
  uint uVar7;
  uint uStack_68;
  channel_page_t iface_supported_1;
  channel_page_t iface_supported;
  code *pcStack_5c;
  int iStack_58;
  uint uStack_54;
  channel_page_t new_channel_page;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  byte bStack_29;
  undefined1 auStack_28 [3];
  uint8_t channel_num;
  zdp_nwk_mgmt_nwk_update_req_field_t req;
  
  _auStack_28 = 0;
  req.scan_channels = 0;
  bStack_29 = 0xff;
  if (packet == (zdo_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else {
    uVar1 = packet->dst_addr;
    zVar2 = zdo_op_nwk_mgmt_nwk_update_req
                      (packet->payload,(zdp_nwk_mgmt_nwk_update_req_field_t *)auStack_28,false);
    uVar6 = _auStack_28;
    if (CONCAT31(extraout_var,zVar2) == 0) {
      channel_page.u32 = _auStack_28 & 0x7ffffff;
      uVar7 = req.scan_channels & 0xff;
      if (uVar7 == 0xfe) {
        iVar3 = core_globals_get();
        if ((*(int *)(iVar3 + 0xa30) == 0) ||
           (iVar3 = core_globals_get(), *(uint *)(iVar3 + 0xa30) == (uVar6 & 0x7ffffff))) {
          bVar4 = 0;
          for (uVar6 = uVar6 & 0x7ffffff; uVar6 != 0; uVar6 = uVar6 & uVar6 - 1) {
            bVar4 = bVar4 + 1;
          }
          if (bVar4 < 2) {
            bStack_29 = 0xff;
            channel_page_get_next_channel(channel_page,&bStack_29);
            iface_supported_1.u32 = 0;
            iVar3 = nwk_mm_get_pib_attr(0,99,&iface_supported_1,4);
            if ((iVar3 == 0) &&
               (((iface_supported_1.u32 & 0x7ffffff) >> (bStack_29 & 0x1f) & 1) != 0)) {
              uStack_54 = 1 << (bStack_29 & 0x1f) & 0x7ffffff;
              nwk_mm_set_pib_attr(0x61,&uStack_54);
              return 0xfe;
            }
            uVar5 = 0x80;
          }
          else {
            uVar5 = 0x80;
          }
        }
        else {
          uVar5 = 0x8d;
        }
      }
      else {
        if (uVar7 == 0xff) {
          iVar3 = aps_secur_is_centralized();
          if ((iVar3 != 0) && (req.scan_channels._3_1_ != '\0')) {
            return 0xfe;
          }
          iVar3 = core_globals_get();
          *(channel_page_t *)(iVar3 + 8) = channel_page;
          bVar4 = req.scan_channels._3_1_;
          iVar3 = core_globals_get();
          *(ushort *)(iVar3 + 0x9dc) = (ushort)bVar4;
          return 0xfe;
        }
        if (uVar7 < 6) {
          if (uVar1 < 0xfff8) {
            bStack_29 = 0xff;
            uStack_68 = 0;
            nwk_mm_get_pib_attr(0,99,&uStack_68,4);
            if ((uVar6 & 0x7ffffff) == (uStack_68 & 0x7ffffff & uVar6 & 0x7ffffff)) {
              iStack_58 = zdo_packet_clone(resp);
              if (iStack_58 != 0) {
                iface_supported_1.u32 =
                     (uint)CONCAT21(iface_supported_1.u32._2_2_,(undefined1)req.scan_channels) << 8;
                iface_supported.u32 = _auStack_28;
                pcStack_5c = zdo_mgmt_ed_scan_handler;
                uStack_54 = 0;
                new_channel_page.u32 = 0;
                uStack_4c = 0;
                uStack_48 = 0;
                uStack_44 = 0;
                uStack_40 = 0;
                uStack_3c = 0;
                uStack_38 = 0;
                uStack_34 = 0;
                uStack_30 = 0;
                zmsg_add_footer(*(undefined4 *)(iStack_58 + 0x14),&uStack_54,0x28);
                nwk_nlme_scan(&iface_supported_1);
                ezb_err_to_zdp_status();
                return 0xfe;
              }
              uVar5 = 0x8a;
            }
            else {
              uVar5 = 0x86;
            }
          }
          else {
            uVar5 = 0x80;
          }
        }
        else {
          log_write(2,"ZDO_NWK_MGMT","Mgmt_NWK_Update_req: Invalid ScanDuration value: 0x%02x",uVar7
                   );
          uVar5 = 0x80;
        }
      }
      uStack_54 = CONCAT31(uStack_54._1_3_,uVar5);
      zmsg_append_bytes(resp->payload,1,&uStack_54);
      zVar2 = '\0';
    }
    else {
      zVar2 = 0xfe;
    }
  }
  return zVar2;
}

