/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_cmd_to_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_cmd_to_packet(zcl_packet_t *packet,uint8_t frame_type,uint8_t manuf_specific,
                           uint8_t direction,uint8_t dis_default_rsp,uint16_t manuf_code,
                           uint8_t command_id,uint16_t cluster_id,uint8_t src_ep,uint8_t dst_ep,
                           ezb_address_t *dst_addr,uint16_t length,void *payload,_Bool check)

{
  undefined2 uVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  undefined2 in_register_0000203e;
  undefined3 in_register_00002041;
  undefined2 in_register_00002046;
  undefined1 in_stack_00000000;
  undefined3 in_stack_00000009;
  undefined2 in_stack_0000000c;
  undefined2 in_stack_00000012;
  
  if (packet == (zcl_packet_t *)0x0) {
    eVar3 = 2;
  }
  else {
    iVar2 = af_get_ep_desc(in_stack_00000000);
    if ((iVar2 == 0) ||
       (((uVar1 = *(undefined2 *)(iVar2 + 2), (char)payload != '\0' &&
         (iVar2 = af_endpoint_is_gateway(in_stack_00000000), iVar2 == 0)) &&
        (iVar2 = zcl_get_cluster_desc
                           (in_stack_00000000,CONCAT22(in_register_00002046,cluster_id),
                            (CONCAT31(in_register_00002035,direction) == 0) + '\x01'), iVar2 == 0)))
       ) {
      eVar3 = 5;
    }
    else {
      zcl_packet_setup_header
                (packet,CONCAT31(in_register_0000202d,frame_type),
                 CONCAT31(in_register_00002031,manuf_specific),
                 CONCAT31(in_register_00002035,direction),
                 CONCAT31(in_register_00002039,dis_default_rsp),
                 CONCAT22(in_register_0000203e,manuf_code),CONCAT31(in_register_00002041,command_id)
                );
      zcl_packet_setup_stamp
                (packet,in_stack_00000000,src_ep,CONCAT22(in_register_00002046,cluster_id),uVar1,
                 *_dst_ep,_dst_ep + 2);
      zcl_packet_add_payload(packet,in_stack_0000000c,_length);
      eVar3 = 0;
    }
  }
  return eVar3;
}

