/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_disc_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_disc_attr_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ushort uVar1;
  zcl_status_t zVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  zmsg_t *unaff_s4;
  ushort uStack_38;
  uint16_t uStack_36;
  uint uStack_34;
  uint16_t offset;
  zcl_disc_attr_req_s disc_attr_req;
  
  uStack_34 = 0;
  if ((((packet == (zcl_packet_t *)0x0) ||
       (unaff_s4 = packet->payload, unaff_s4 == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x3ff,
                          "zcl_general_disc_attr_handler",
                          "packet && packet->payload && rsp && rsp->payload");
_L0:
    uVar6 = 1;
  }
  else {
    iVar3 = af_get_ep_desc((packet->header).dst_ep);
    if (iVar3 == 0) {
      uVar6 = 0x81;
      goto _L0;
    }
    uVar5 = (uint)(packet->header).cluster_id;
    if (((packet->header).fc & 8) == 0) goto _L0;
    uVar6 = 2;
  }
  iVar3 = af_endpoint_get_cluster_desc(uVar5,uVar6);
  if (iVar3 != 0) {
    uVar5 = zmsg_get_length(unaff_s4);
    uStack_36 = 0;
    uVar7 = 0;
_L0:
    do {
      if (uVar5 <= uStack_36) {
        zVar2 = zcl_packet_setup_response(rsp,packet,0xd);
        return zVar2;
      }
      af_read_le16(unaff_s4,&uStack_36,(uint16_t *)&stack0xffffffcc);
      af_read_le8(unaff_s4,&uStack_36,(uint8_t *)&offset);
      if (uStack_36 != uVar5) {
        uVar6 = 0x80;
        goto _L0;
      }
      uStack_38 = CONCAT11(uStack_38._1_1_,1);
      zmsg_append_bytes(rsp->payload,&uStack_38);
      puVar4 = (ushort *)0x0;
      do {
        do {
          puVar4 = (ushort *)zcl_cluster_get_next_attr_desc(iVar3,puVar4);
          if (puVar4 == (ushort *)0x0) goto _L0;
          uVar1 = *puVar4;
        } while ((uint)uVar1 < (uStack_34 & 0xffff));
        if (((*(byte *)((int)puVar4 + 3) & 0x40) == 0) && (uVar1 != 0xfffd)) {
          uStack_38 = uVar1;
          zmsg_append_bytes(rsp->payload,2,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,(char)puVar4[1]);
          zmsg_append_bytes(rsp->payload,1,&uStack_38);
          uVar7 = uVar7 + 1 & 0xff;
        }
      } while (uVar7 < (uStack_34 >> 0x10 & 0xff));
      uStack_38 = uStack_38 & 0xff00;
      zmsg_write_bytes(rsp->payload,0,1,&uStack_38);
    } while( true );
  }
  uVar6 = 0xc3;
_L0:
  zVar2 = zcl_packet_setup_default_response(rsp,packet,uVar6);
  return zVar2;
}

