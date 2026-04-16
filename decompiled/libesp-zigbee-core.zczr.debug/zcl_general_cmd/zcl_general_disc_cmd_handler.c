/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_disc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_disc_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  zcl_status_t zVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  zmsg_t *unaff_s2;
  uint uVar6;
  byte bVar7;
  byte bStack_2d;
  uint uStack_2c;
  uint8_t *list;
  byte abStack_24 [2];
  uint16_t offset;
  zcl_disc_cmd_req_s disc_cmd_req;
  
  abStack_24[0] = 0;
  abStack_24[1] = 0;
  if ((((packet == (zcl_packet_t *)0x0) ||
       (unaff_s2 = packet->payload, unaff_s2 == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    uVar4 = __assert_func("//build/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x391,
                          "zcl_general_disc_cmd_handler",
                          "packet && packet->payload && rsp && rsp->payload");
_L0:
    uVar5 = 1;
  }
  else {
    iVar2 = af_get_ep_desc((packet->header).dst_ep);
    if (iVar2 == 0) {
      uVar5 = 0x81;
      goto _L0;
    }
    uVar4 = (uint)(packet->header).cluster_id;
    if (((packet->header).fc & 8) == 0) goto _L0;
    uVar5 = 2;
  }
  puVar3 = (undefined2 *)af_endpoint_get_cluster_desc(uVar4,uVar5);
  if (puVar3 == (undefined2 *)0x0) {
    uVar5 = 0xc3;
  }
  else {
    uVar4 = zmsg_get_length(unaff_s2);
    list._2_2_ = 0;
    af_read_le8(unaff_s2,(uint16_t *)((int)&list + 2),abStack_24);
    af_read_le8(unaff_s2,(uint16_t *)((int)&list + 2),abStack_24 + 1);
    if (list._2_2_ == uVar4) {
      uStack_2c = uStack_2c & 0xffffff00;
      zmsg_append_bytes(rsp->payload,1,&uStack_2c);
      iVar2 = zcl_cluster_template_find(*puVar3,*(undefined1 *)(puVar3 + 1));
      if (iVar2 == 0) {
        uVar5 = 0x8b;
      }
      else {
        if (*(code **)(iVar2 + 0xc) != (code *)0x0) {
          uStack_2c = 0;
          uVar4 = (**(code **)(iVar2 + 0xc))((packet->header).cmd_id == '\x11',&uStack_2c);
          bVar7 = 0;
          uVar6 = 0;
          while (((uVar6 < uVar4 && (uStack_2c != 0)) && (bVar7 < abStack_24[1]))) {
            bStack_2d = *(byte *)(uStack_2c + uVar6);
            if (abStack_24[0] <= bStack_2d) {
              zmsg_append_bytes(rsp->payload,1,&bStack_2d);
              bVar7 = bVar7 + 1;
            }
            uVar6 = uVar6 + 1 & 0xffff;
          }
          bStack_2d = uVar6 == uVar4;
          zmsg_write_bytes(rsp->payload,0,1,&bStack_2d);
          if ((packet->header).cmd_id == '\x11') {
            uVar5 = 0x12;
          }
          else {
            uVar5 = 0x14;
          }
          zVar1 = zcl_packet_setup_response(rsp,packet,uVar5);
          return zVar1;
        }
        uVar5 = 0x8b;
      }
    }
    else {
      uVar5 = 0x80;
    }
  }
_L0:
  zVar1 = zcl_packet_setup_default_response(rsp,packet,uVar5);
  return zVar1;
}

