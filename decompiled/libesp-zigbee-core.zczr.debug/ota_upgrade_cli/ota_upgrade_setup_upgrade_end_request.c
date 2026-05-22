/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_setup_upgrade_end_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_setup_upgrade_end_request
          (zcl_packet_t *sent_packet,zcl_packet_t *recv_packet,
          ota_upgrade_downloading_context_t *context,uint8_t status)

{
  int iVar1;
  int unaff_s2;
  uint32_t auStack_24 [4];
  
  if (((sent_packet == (zcl_packet_t *)0x0) || (recv_packet == (zcl_packet_t *)0x0)) ||
     (context == (ota_upgrade_downloading_context_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",599
                  ,"ota_upgrade_setup_upgrade_end_request","sent_packet && recv_packet && context");
  }
  else {
    unaff_s2 = zcl_packet_setup_response_with_extension(6,1,0);
    if (unaff_s2 != 0) goto _L0;
  }
  auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,status);
  iVar1 = zmsg_append_bytes(sent_packet->payload,1,auStack_24);
  if (iVar1 == 0) {
    auStack_24[0]._0_2_ = *(context->attr).manuf_code;
    iVar1 = zmsg_append_bytes(sent_packet->payload,2,auStack_24);
    if (iVar1 == 0) {
      auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,*(context->attr).image_type);
      iVar1 = zmsg_append_bytes(sent_packet->payload,2,auStack_24);
      if (iVar1 == 0) {
        auStack_24[0] = (context->file).downloading_version;
        iVar1 = zmsg_append_bytes(sent_packet->payload,4,auStack_24);
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

