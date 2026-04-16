/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_identify_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t identify_cluster_identify_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte ep_id;
  ezb_zcl_status_t eVar1;
  uint uVar2;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  undefined4 uVar5;
  uint16_t uStack_24;
  uint16_t uStack_22;
  uint16_t offset;
  uint16_t identify_time;
  
  uStack_22 = 0;
  uStack_24 = 0;
  ep_id = (packet->header).dst_ep;
  if (packet != (zcl_packet_t *)0x0) {
    if (rsp == (zcl_packet_t *)0x0) {
      uVar5 = 0xfe;
      goto _L0;
    }
    af_read_le16(packet->payload,&uStack_24,&uStack_22);
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < uStack_24) {
      uVar5 = 0x80;
      goto _L0;
    }
    pzVar3 = identify_srv_get_attr_desc(ep_id,0);
    pzVar4 = identify_srv_get_attr_desc(ep_id,0xeff0);
    if (pzVar4 != (zcl_attr_desc_t *)0x0) {
      if (pzVar3 == (zcl_attr_desc_t *)0x0) {
        uVar5 = 0x86;
      }
      else if (pzVar3->data_p == (void *)0x0) {
        uVar5 = 0x86;
      }
      else {
        zcl_message_set_identify_attr_value((ushort)ep_id,uStack_22);
        uVar5 = 0;
      }
      goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xee,
                  "identify_cluster_identify_cmd_handler","identify_timer_ctx_attr_desc");
  }
  uVar5 = 0xfe;
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar5);
  return eVar1;
}

