/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_setup_query_next_image_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_setup_query_next_image_request
          (zcl_packet_t *sent_packet,zcl_packet_t *recv_packet,
          ota_upgrade_downloading_context_t *context)

{
  int iVar1;
  uint32_t *puVar2;
  int unaff_s2;
  uint uStack_14;
  
  if (((sent_packet == (zcl_packet_t *)0x0) || (recv_packet == (zcl_packet_t *)0x0)) ||
     (context == (ota_upgrade_downloading_context_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0x21f,
                  "ota_upgrade_setup_query_next_image_request",
                  "sent_packet && recv_packet && context");
  }
  else {
    unaff_s2 = zcl_packet_setup_response_with_extension(1,0);
    if (unaff_s2 != 0) goto _L0;
  }
  uStack_14 = uStack_14 & 0xffffff00;
  iVar1 = zmsg_append_bytes(sent_packet->payload,1,&uStack_14);
  if (iVar1 == 0) {
    uStack_14._0_2_ = *(context->attr).manuf_code;
    iVar1 = zmsg_append_bytes(sent_packet->payload,2,&uStack_14);
    if (iVar1 == 0) {
      uStack_14 = CONCAT22(uStack_14._2_2_,*(context->attr).image_type);
      iVar1 = zmsg_append_bytes(sent_packet->payload,2,&uStack_14);
      if (iVar1 == 0) {
        puVar2 = (context->attr).current_file_version;
        if (puVar2 == (uint32_t *)0x0) {
          uStack_14 = 0xffffffff;
        }
        else {
          uStack_14 = *puVar2;
        }
        iVar1 = zmsg_append_bytes(sent_packet->payload,4,&uStack_14);
        if (iVar1 != 0) {
          unaff_s2 = 0x89;
        }
      }
      else {
        unaff_s2 = 0x89;
      }
    }
    else {
      unaff_s2 = 0x89;
    }
  }
  else {
    unaff_s2 = 0x89;
  }
_L0:
  return (ezb_zcl_status_t)unaff_s2;
}

