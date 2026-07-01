/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_frame_fill_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zcl_frame_fill_header(zcl_packet_t *packet)

{
  byte bVar1;
  uint16_t uVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint8_t uVar5;
  int iVar6;
  zmsg_t *payload;
  uint16_t extraout_a1;
  char *pcVar7;
  uint16_t uStack_42;
  uint auStack_40 [5];
  undefined4 uStack_2c;
  zcl_packet_t *pzStack_28;
  code *pcStack_24;
  undefined4 uStack_18;
  uint8_t buffer [5];
  
  uStack_18 = 0;
  buffer[0] = '\0';
  bVar1 = (packet->header).fc;
  if ((bVar1 & 4) == 0) {
    uVar4 = 3;
  }
  else {
    uVar4 = 5;
  }
  if ((bVar1 & 0x20) == 0) {
    uVar5 = zcl_generate_tsn();
    (packet->header).tsn = uVar5;
  }
  bVar1 = (packet->header).fc;
  (packet->header).fc = bVar1 & 0xdf;
  if ((bVar1 & 4) == 0) {
    uStack_18 = CONCAT13(uStack_18._3_1_,
                         CONCAT12((packet->header).cmd_id,CONCAT11((packet->header).tsn,bVar1)));
  }
  else {
    uVar2 = (packet->header).manuf_code;
    uStack_18 = CONCAT13((packet->header).tsn,
                         CONCAT12((char)(uVar2 >> 8),CONCAT11((char)uVar2,bVar1)));
    buffer[0] = (packet->header).cmd_id;
  }
  uStack_18 = uStack_18 & 0xffffffdf;
  iVar6 = zmsg_prepend_bytes(packet->payload,uVar4,&uStack_18);
  if (iVar6 == 0) {
    return (packet->header).tsn;
  }
  pcVar7 = "zcl_frame_fill_header";
  pcVar3 = zcl_packet_read_variable_attr_actual_size;
  payload = (zmsg_t *)
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x162,
                          "zmsg_prepend_bytes(packet->payload, length, buffer) == 0");
  auStack_40[0] = 0;
  auStack_40[1] = 0;
  auStack_40[2] = 0;
  auStack_40[3] = 0;
  uStack_42 = extraout_a1;
  uStack_2c = uVar4;
  pzStack_28 = packet;
  pcStack_24 = pcVar3;
  iVar6 = zcl_attr_type_is_composite(pcVar7);
  if (iVar6 == 0) {
    uVar5 = zcl_get_attr_value_size(pcVar7,0);
  }
  else if (((uint)(pcVar7 + -0x41) & 0xff) < 2) {
    af_read_bytes(payload,&uStack_42,1,(uint8_t *)auStack_40);
    uVar5 = (char)auStack_40[0] + '\x01';
  }
  else if (((uint)(pcVar7 + -0x43) & 0xff) < 2) {
    af_read_bytes(payload,&uStack_42,2,(uint8_t *)auStack_40);
    uVar5 = (char)auStack_40[0] + '\x02';
  }
  else if (pcVar7 == (char *)0x49) {
    af_read_bytes(payload,&uStack_42,2,(uint8_t *)auStack_40);
    uVar5 = (uint8_t)(((auStack_40[0] & 0xffff) + 1) * 0x20000 >> 0x10);
  }
  else if (pcVar7 == (char *)0x4a) {
    af_read_bytes(payload,&uStack_42,2,(uint8_t *)auStack_40);
    uVar5 = (char)((auStack_40[0] << 0x12) >> 0x10) + '\x02';
  }
  else {
    uVar5 = '\0';
  }
  return uVar5;
}

