/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_setup_upgrade_end_request
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
  ota_upgrade_downloading_context_t *unaff_s1;
  int iVar1;
  int iVar2;
  ezb_err_t eVar3;
  uint32_t auStack_24 [4];
  
  if (((sent_packet == (zcl_packet_t *)0x0) || (recv_packet == (zcl_packet_t *)0x0)) ||
     (unaff_s1 = context, context == (ota_upgrade_downloading_context_t *)0x0)) {
    status = '\0';
    sent_packet = (zcl_packet_t *)__assert_func(0,0,0);
  }
  iVar1 = zcl_packet_setup_response_with_extension(6,1,0);
  if (iVar1 == 0) {
    auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,status);
    iVar2 = zmsg_append_bytes(sent_packet->payload,1,auStack_24);
    if (((iVar2 == 0) &&
        (eVar3 = zmsg_append_le16(sent_packet->payload,*(unaff_s1->attr).manuf_code), eVar3 == 0))
       && (eVar3 = zmsg_append_le16(sent_packet->payload,*(unaff_s1->attr).image_type), eVar3 == 0))
    {
      auStack_24[0] = (unaff_s1->file).downloading_version;
      iVar2 = zmsg_append_bytes(sent_packet->payload,4,auStack_24);
      if (iVar2 == 0) goto _L0;
    }
    iVar1 = 0x89;
  }
_L0:
  return (ezb_zcl_status_t)iVar1;
}

