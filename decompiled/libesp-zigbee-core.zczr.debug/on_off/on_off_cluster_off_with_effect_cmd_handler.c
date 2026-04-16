/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_off_with_effect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t on_off_cluster_off_with_effect_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  int iVar2;
  uint uVar3;
  zcl_attr_desc_t *pzVar4;
  undefined3 extraout_var;
  uint unaff_s3;
  uint8_t unaff_s4;
  uint16_t uStack_24;
  uint8_t local_22;
  uint8_t uStack_21;
  uint16_t offset;
  uint8_t effect_variant;
  uint8_t effect_id;
  
  uStack_21 = '\0';
  local_22 = '\0';
  uStack_24 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x18e,
                  "on_off_cluster_off_with_effect_cmd_handler","packet && rsp");
_L0:
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x192,
                  "on_off_cluster_off_with_effect_cmd_handler","ep_desc");
  }
  else {
    unaff_s3 = (uint)(packet->header).dst_ep;
    unaff_s4 = (packet->header).cmd_id;
    iVar2 = af_get_ep_desc(unaff_s3);
    if (iVar2 == 0) goto _L0;
    af_read_le8(packet->payload,&uStack_24,&uStack_21);
    af_read_le8(packet->payload,&uStack_24,&local_22);
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_24) {
      iVar2 = 0x80;
      goto _L0;
    }
  }
  pzVar4 = on_off_srv_get_attr_desc((uint8_t)unaff_s3,0x4000);
                    /* WARNING: Load size is inaccurate */
  if ((pzVar4 != (zcl_attr_desc_t *)0x0) && (*pzVar4->data_p != '\0')) {
    zcl_message_scenes_store_scene(unaff_s3,0,0);
    *(undefined1 *)pzVar4->data_p = 0;
  }
  eVar1 = zcl_message_on_off_with_off_effect(packet,uStack_21,local_22);
  iVar2 = CONCAT31(extraout_var,eVar1);
  if (iVar2 == 0) {
    on_off_process_transition((packet->header).dst_ep,unaff_s4,'\0',0,0);
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,iVar2);
  return eVar1;
}

