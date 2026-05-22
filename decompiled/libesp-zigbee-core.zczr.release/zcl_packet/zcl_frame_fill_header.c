/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_frame_fill_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zcl_frame_fill_header(zcl_packet_t *packet)

{
  byte bVar1;
  byte bVar2;
  uint16_t uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint8_t uVar7;
  uint uVar8;
  undefined4 uStack_18;
  uint8_t buffer [5];
  
  bVar1 = (packet->header).fc;
  uStack_18 = 0;
  buffer[0] = '\0';
  iVar6 = (-(uint)((bVar1 & 4) == 0) & 0xfffffffe) + 5;
  if ((bVar1 & 0x20) == 0) {
    iVar5 = core_globals_get();
    uVar7 = *(uint8_t *)(iVar5 + 0xd14);
    *(uint8_t *)(iVar5 + 0xd14) = uVar7 + '\x01';
    (packet->header).tsn = uVar7;
  }
  bVar1 = (packet->header).fc;
  uVar7 = (packet->header).tsn;
  (packet->header).fc = bVar1 & 0xdf;
  uStack_18 = CONCAT31(uStack_18._1_3_,bVar1) & 0xffffffdf;
  bVar2 = (packet->header).cmd_id;
  uVar8 = (uint)bVar2;
  if ((bVar1 & 4) == 0) goto _L0;
  uVar3 = (packet->header).manuf_code;
  uStack_18._0_2_ = CONCAT11((char)uVar3,(undefined1)uStack_18);
  uStack_18._0_3_ = CONCAT12((char)(uVar3 >> 8),(undefined2)uStack_18);
  uStack_18 = CONCAT13(uVar7,(undefined3)uStack_18);
  buffer[0] = bVar2;
  while (iVar6 = zmsg_prepend_bytes(packet->payload,iVar6,&uStack_18), iVar6 != 0) {
    uVar7 = '\0';
    iVar6 = __assert_func(0,0,0);
_L0:
    uVar4 = uStack_18;
    uStack_18._0_2_ = CONCAT11(uVar7,(undefined1)uStack_18);
    uStack_18._3_1_ = SUB41(uVar4,3);
    uStack_18._0_3_ = CONCAT12((char)uVar8,(undefined2)uStack_18);
  }
  return '\0';
}

