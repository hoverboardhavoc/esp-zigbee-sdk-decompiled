/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_device_service_discovery_rsp_handler(void *arg)

{
  ushort uVar1;
  zmsg_t *pzVar2;
  zdp_status_t zVar3;
  zdo_packet_payload_t *payload;
  ezb_shortaddr_t *peVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bStack_3b;
  uint16_t uStack_3a;
  undefined1 uStack_38;
  uint8_t device_info;
  uint16_t offset;
  zdp_active_ep_rsp_field_t rsp;
  undefined4 uStack_28;
  ezb_shortaddr_t *peStack_24;
  
  if (arg == (void *)0x0) {
    return 0xfe;
  }
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 0x8004) {
    memset(&uStack_38,0,0x18);
    pzVar2 = *(zmsg_t **)((int)arg + 0x14);
    peVar4 = peStack_24;
    if (pzVar2 != (zmsg_t *)0x0) {
      uStack_3a = 0;
      bStack_3b = 0;
      uVar6 = zmsg_get_length(pzVar2);
      af_read_le8(pzVar2,&uStack_3a,&uStack_38);
      af_read_le16(pzVar2,&uStack_3a,&offset);
      af_read_le8(pzVar2,&uStack_3a,&rsp.status);
      peVar4 = peStack_24;
      if ((int)((uint)uStack_3a + (rsp._0_4_ & 0xff)) <= (int)uVar6) {
        if ((_uStack_38 & 0xff) == 0) {
          af_read_le8(pzVar2,&uStack_3a,&rsp.active_ep_count);
          af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&rsp.field_0x6);
          af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&rsp.active_ep_list);
          af_read_le8(pzVar2,&uStack_3a,&bStack_3b);
          rsp.active_ep_list._0_3_ =
               CONCAT12(bStack_3b >> 4 | bStack_3b << 4,rsp.active_ep_list._0_2_);
          af_read_le8(pzVar2,&uStack_3a,(uint8_t *)((int)&rsp.active_ep_list + 3));
          uVar7 = (uint)rsp.active_ep_list >> 0x18;
          peStack_24 = (ezb_shortaddr_t *)calloc(uVar7,2);
          uVar8 = 0;
          if (peStack_24 == (ezb_shortaddr_t *)0x0) {
            peVar4 = (ezb_shortaddr_t *)0x0;
            if (uVar7 != 0) goto _L0;
          }
          else {
            for (; uVar8 < (uint)rsp.active_ep_list >> 0x18; uVar8 = uVar8 + 1 & 0xff) {
              af_read_le16(pzVar2,&uStack_3a,(uint16_t *)((int)peStack_24 + uVar8 * 2));
            }
          }
          af_read_le8(pzVar2,&uStack_3a,(uint8_t *)&uStack_28);
          peStack_24 = (ezb_shortaddr_t *)
                       mm_realloc(peStack_24,
                                  ((uint)rsp.active_ep_list >> 0x18) + ((uint)uStack_28 & 0xff),2);
          uVar7 = (uint)rsp.active_ep_list >> 0x18;
          if (peStack_24 == (ezb_shortaddr_t *)0x0) {
            peVar4 = peStack_24;
            if (((uint)uStack_28 & 0xff) + uVar7 != 0) goto _L0;
          }
          else {
            for (; uVar7 < ((uint)rsp.active_ep_list >> 0x18) + ((uint)uStack_28 & 0xff);
                uVar7 = uVar7 + 1 & 0xff) {
              af_read_le16(pzVar2,&uStack_3a,peStack_24 + uVar7);
            }
          }
        }
        peVar4 = peStack_24;
        if (uStack_3a <= uVar6) {
          zdo_cb_address_rsp((zdp_address_rsp_field_t *)&uStack_38,
                             (zdo_packet_ctx_t *)((int)arg + 8));
          zVar3 = '\0';
          peVar4 = peStack_24;
          goto _L0;
        }
      }
    }
_L0:
    peStack_24 = peVar4;
    zVar3 = 0xfe;
    peVar4 = peStack_24;
    goto _L0;
  }
  if (uVar1 < 0x8005) {
    if (uVar1 == 0x8002) {
      pzVar2 = *(zmsg_t **)((int)arg + 0x14);
      _uStack_38 = 0;
      rsp.status = '\0';
      rsp._1_1_ = 0;
      rsp.nwk_addr_of_interest = 0;
      rsp.active_ep_count = '\0';
      rsp._5_3_ = 0;
      rsp.active_ep_list = (uint8_t *)0x0;
      uStack_28 = (ezb_shortaddr_t *)0x0;
      if (pzVar2 == (zmsg_t *)0x0) {
        return 0xfe;
      }
      uStack_3a = 0;
      uVar6 = zmsg_get_length(pzVar2);
      af_read_le8(pzVar2,&uStack_3a,&uStack_38);
      af_read_le16(pzVar2,&uStack_3a,&offset);
      if (uVar6 < uStack_3a) {
        return 0xfe;
      }
      if (uStack_38 != '\0') {
        rsp.status = '\0';
        rsp._1_1_ = 0;
        rsp.nwk_addr_of_interest = 0;
        rsp.active_ep_count = '\0';
        rsp._5_3_ = 0;
        rsp.active_ep_list = (uint8_t *)0x0;
        uStack_28 = (ezb_shortaddr_t *)0x0;
        goto _L0;
      }
      af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&rsp);
      af_read_le8(pzVar2,&uStack_3a,(uint8_t *)&rsp.nwk_addr_of_interest);
      af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&rsp.active_ep_count);
      af_read_le8(pzVar2,&uStack_3a,&rsp.field_0x6);
      af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&rsp.active_ep_list);
      af_read_le16(pzVar2,&uStack_3a,(uint16_t *)((int)&rsp.active_ep_list + 2));
      af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&uStack_28);
      af_read_le8(pzVar2,&uStack_3a,(uint8_t *)((int)&uStack_28 + 2));
    }
    else {
      if (uVar1 != 0x8003) {
        if (1 < (ushort)(uVar1 + 0x8000)) {
          return 0x84;
        }
        payload = *(zdo_packet_payload_t **)((int)arg + 0x14);
        _uStack_38 = 0;
        rsp.status = '\0';
        rsp._1_1_ = 0;
        rsp.nwk_addr_of_interest = 0;
        rsp.active_ep_count = '\0';
        rsp._5_3_ = 0;
        rsp.active_ep_list = (uint8_t *)0x0;
        uStack_28 = (ezb_shortaddr_t *)0x0;
        if (payload != (zdo_packet_payload_t *)0x0) {
          if (uVar1 == 0x8000) {
            zVar3 = zdo_op_nwk_addr_rsp(payload,'\x02',(zdp_nwk_addr_rsp_field_t *)&uStack_38,false)
            ;
            iVar5 = CONCAT31(extraout_var,zVar3);
          }
          else {
            zVar3 = zdo_op_ieee_addr_rsp
                              (payload,'\x02',(zdp_ieee_addr_rsp_field_t *)&uStack_38,false);
            iVar5 = CONCAT31(extraout_var_00,zVar3);
          }
          if (iVar5 == 0) {
            uStack_3a = 0;
            nwk_address_update(&device_info,(uint)rsp._4_4_ >> 0x10,&uStack_3a);
            zdo_cb_address_rsp((zdp_address_rsp_field_t *)&uStack_38,
                               (zdo_packet_ctx_t *)((int)arg + 8));
            zVar3 = '\0';
            peVar4 = uStack_28;
            goto _L0;
          }
        }
        zVar3 = 0xfe;
        peVar4 = uStack_28;
        goto _L0;
      }
      pzVar2 = *(zmsg_t **)((int)arg + 0x14);
      _uStack_38 = 0;
      rsp._0_4_ = rsp._0_4_ & 0xffff0000;
      if (pzVar2 == (zmsg_t *)0x0) {
        return 0xfe;
      }
      uStack_3a = 0;
      uVar6 = zmsg_get_length(pzVar2);
      af_read_le8(pzVar2,&uStack_3a,&uStack_38);
      af_read_le16(pzVar2,&uStack_3a,&offset);
      if (uVar6 < uStack_3a) {
        return 0xfe;
      }
      if (uStack_38 != '\0') {
        rsp._0_4_ = rsp._0_4_ & 0xffff0000;
        goto _L0;
      }
      af_read_le16(pzVar2,&uStack_3a,(uint16_t *)&rsp);
    }
    if (uVar6 < uStack_3a) {
      return 0xfe;
    }
_L0:
    zdo_cb_address_rsp((zdp_address_rsp_field_t *)&uStack_38,(zdo_packet_ctx_t *)((int)arg + 8));
    return '\0';
  }
  if ((uVar1 != 0x8005) && (uVar1 != 0x8006)) {
    return 0x84;
  }
  _uStack_38 = 0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  rsp.nwk_addr_of_interest = 0;
  rsp.active_ep_count = '\0';
  rsp._5_3_ = 0;
  pzVar2 = *(zmsg_t **)((int)arg + 0x14);
  if (pzVar2 != (zmsg_t *)0x0) {
    uStack_3a = 0;
    uVar6 = zmsg_get_length(pzVar2);
    af_read_le8(pzVar2,&uStack_3a,&uStack_38);
    af_read_le16(pzVar2,&uStack_3a,&offset);
    af_read_le8(pzVar2,&uStack_3a,&rsp.status);
    if (uStack_3a <= uVar6) {
      if ((uStack_38 == '\0') && (uVar7 = rsp._0_4_ & 0xff, uVar7 != 0)) {
        rsp._4_4_ = calloc(uVar7,1);
        if (((uint8_t *)rsp._4_4_ == (uint8_t *)0x0) ||
           (af_read_bytes(pzVar2,&uStack_3a,(uint16_t)uVar7,(uint8_t *)rsp._4_4_), uVar6 < uStack_3a
           )) goto _L0;
      }
      else {
        rsp.active_ep_count = '\0';
        rsp._5_3_ = 0;
      }
      zdo_cb_address_rsp((zdp_address_rsp_field_t *)&uStack_38,(zdo_packet_ctx_t *)((int)arg + 8));
      zVar3 = '\0';
      peVar4 = (ezb_shortaddr_t *)rsp._4_4_;
      goto _L0;
    }
  }
_L0:
  zVar3 = 0xfe;
  peVar4 = (ezb_shortaddr_t *)rsp._4_4_;
_L0:
  if (peVar4 != (ezb_shortaddr_t *)0x0) {
    mm_free();
  }
  return zVar3;
}

