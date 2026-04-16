/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_setup_image_block_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_setup_image_block_request
          (zcl_packet_t *sent_packet,zcl_packet_t *recv_packet,
          ota_upgrade_downloading_context_t *context)

{
  int iVar1;
  undefined4 uVar2;
  uint16_t uVar3;
  uint16_t *puVar4;
  int unaff_s2;
  char cVar5;
  zcl_packet_payload_t *pzVar6;
  uint auStack_24 [3];
  
  if ((context->attr).min_block_period == (uint16_t *)0x0) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x02';
  }
  if (((sent_packet == (zcl_packet_t *)0x0) || (recv_packet == (zcl_packet_t *)0x0)) ||
     (context == (ota_upgrade_downloading_context_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0x23c,
                  "ota_upgrade_setup_image_block_request","sent_packet && recv_packet && context");
  }
  else {
    unaff_s2 = zcl_packet_setup_response_with_extension(sent_packet,3,1,0);
    if (unaff_s2 != 0) goto _L0;
  }
  auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,cVar5) | 1;
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
        if (iVar1 == 0) {
          auStack_24[0] = *(context->attr).file_offset;
          iVar1 = zmsg_append_bytes(sent_packet->payload,4,auStack_24);
          if (iVar1 == 0) {
            auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,(context->config).allowed_block_size);
            iVar1 = zmsg_append_bytes(sent_packet->payload,1,auStack_24);
            if (iVar1 == 0) {
              pzVar6 = sent_packet->payload;
              uVar2 = nwk_get_extended_address();
              iVar1 = zmsg_append_bytes(pzVar6,8,uVar2);
              if (iVar1 == 0) {
                if (cVar5 == '\0') {
                  unaff_s2 = 0;
                }
                else {
                  puVar4 = (context->attr).min_block_period;
                  if (puVar4 == (uint16_t *)0x0) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = *puVar4;
                  }
                  auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,uVar3);
                  iVar1 = zmsg_append_bytes(sent_packet->payload,2,auStack_24);
                  if (iVar1 != 0) {
                    unaff_s2 = 0x89;
                  }
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
  }
  else {
    unaff_s2 = 0x89;
  }
_L0:
  return (ezb_zcl_status_t)unaff_s2;
}

