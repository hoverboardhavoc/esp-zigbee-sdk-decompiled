/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_permit_joining_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_permit_joining_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  ushort uVar1;
  zdp_status_t zVar2;
  undefined3 extraout_var;
  int iVar3;
  uint8_t *puVar4;
  zdp_nwk_mgmt_permit_joining_rsp_field_t zVar5;
  zdp_nwk_mgmt_permit_joining_rsp_field_t azStack_28 [4];
  zdp_nwk_mgmt_permit_joining_rsp_field_t rsp;
  uint8_t uStack_23;
  zdp_nwk_mgmt_permit_joining_req_field_t req;
  
  rsp.status = '\0';
  uStack_23 = '\0';
  azStack_28[0].status = '\0';
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
    zVar2 = zdo_op_nwk_mgmt_permit_joining_req
                      (packet->payload,(zdp_nwk_mgmt_permit_joining_req_field_t *)&rsp,false);
    if (CONCAT31(extraout_var,zVar2) == 0) {
      zVar5.status = rsp.status;
      if (rsp.status == 0xff) {
        zVar5.status = 0xfe;
      }
      uStack_23 = '\x01';
      nwk_is_device_zc();
      iVar3 = nwk_is_device_zczr();
      if (iVar3 == 0) {
        azStack_28[0].status = 0x84;
      }
      else {
        iVar3 = zdo_create_mgmt_req(0x36);
        if (iVar3 == 0) {
          azStack_28[0].status = 0x80;
        }
        else {
          puVar4 = (uint8_t *)zdo_mgmt_req_get_param();
          *puVar4 = zVar5.status;
          iVar3 = zdo_send_mgmt_req(iVar3,1);
          azStack_28[0].status = zVar2;
          if (iVar3 != 0) {
            azStack_28[0].status = 0x80;
          }
        }
      }
      if (uVar1 < 0xfff8) {
        zVar2 = zdo_op_nwk_mgmt_permit_joining_rsp(resp->payload,azStack_28,true);
      }
      else {
        zVar2 = 0xfe;
      }
    }
    else {
      zVar2 = 0xfe;
    }
  }
  return zVar2;
}

