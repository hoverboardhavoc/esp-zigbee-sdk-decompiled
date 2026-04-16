/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_active_ep_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_active_ep_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  uint uVar1;
  char *pcVar2;
  zdp_status_t zVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  size_t __nmemb;
  undefined1 local_30 [4];
  zdp_active_ep_rsp_field_t rsp;
  zdp_active_ep_req_field_t req;
  
  rsp.active_ep_list._0_2_ = 0;
  local_30 = (undefined1  [4])0x0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  rsp.nwk_addr_of_interest = 0;
  rsp.active_ep_count = '\0';
  rsp._5_3_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else {
    zVar3 = zdo_op_active_ep_req
                      (packet->payload,(zdp_active_ep_req_field_t *)&rsp.active_ep_list,false);
    if (CONCAT31(extraout_var,zVar3) == 0) {
      uVar1 = (uint)(ushort)rsp.active_ep_list;
      if (uVar1 < 0xfff8) {
        local_30._2_2_ = (ushort)rsp.active_ep_list;
        uVar4 = nwk_get_short_address();
        if (uVar1 == uVar4) {
          local_30 = (undefined1  [4])((uint)local_30 & 0xffffff00);
        }
        else {
          iVar5 = nwk_is_device_zed();
          if (iVar5 == 0) {
            local_30[0] = 0x81;
          }
          else {
            local_30[0] = 0x80;
          }
        }
        if (((uint)local_30 & 0xff) == 0) {
          pcVar2 = (char *)0x0;
          __nmemb = 0;
          while (pcVar2 = (char *)af_device_get_next_endpoint_desc(pcVar2), pcVar2 != (char *)0x0) {
            if (*pcVar2 != '\0') {
              __nmemb = __nmemb + 1 & 0xff;
            }
          }
          pvVar6 = (void *)0x0;
          if (__nmemb != 0) {
            pvVar6 = calloc(__nmemb,1);
            uVar1 = 0;
            pcVar2 = (char *)0x0;
            if (pvVar6 == (void *)0x0) {
              zVar3 = 0x8a;
              goto _L0;
            }
            while (pcVar2 = (char *)af_device_get_next_endpoint_desc(pcVar2), pcVar2 != (char *)0x0)
            {
              if (*pcVar2 != '\0') {
                *(char *)(uVar1 + (int)pvVar6) = *pcVar2;
                uVar1 = uVar1 + 1 & 0xff;
              }
            }
          }
          rsp.status = (ezb_zdp_status_t)__nmemb;
          rsp._4_4_ = pvVar6;
        }
        else {
          rsp._0_4_ = rsp._0_4_ & 0xffffff00;
          rsp.active_ep_count = '\0';
          rsp._5_3_ = 0;
        }
        zVar3 = zdo_op_active_ep_rsp(resp->payload,(zdp_active_ep_rsp_field_t *)local_30,true);
      }
      else {
        zVar3 = 0x8b;
      }
    }
    else {
      zVar3 = 0xfe;
    }
  }
_L0:
  if (rsp._4_4_ != 0) {
    mm_free();
  }
  return zVar3;
}

