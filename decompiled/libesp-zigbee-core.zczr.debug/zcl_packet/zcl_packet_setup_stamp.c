/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_setup_stamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_packet_setup_stamp
               (zcl_packet_t *packet,uint8_t src_ep,uint8_t dst_ep,uint16_t cluster_id,
               uint16_t profile_id,uint8_t addr_mode,uint8_t *addr)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  byte bVar7;
  zcl_packet_t *packet_00;
  uint8_t *extraout_a1;
  uint8_t uVar8;
  undefined *puVar9;
  undefined2 in_register_0000203a;
  int iVar10;
  
  iVar10 = CONCAT22(in_register_0000203a,profile_id);
  if (addr == (uint8_t *)0x0) {
    puVar9 = &_L0;
    uVar8 = 200;
    packet_00 = (zcl_packet_t *)
                __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0xdd);
    if ((packet_00 != (zcl_packet_t *)0x0) && (extraout_a1 != (uint8_t *)0x0)) {
      (packet_00->header).tsn = extraout_a1[0x1e];
      (packet_00->header).cmd_id = uVar8;
      (packet_00->header).manuf_code = *(uint16_t *)(extraout_a1 + 0x1c);
      bVar7 = extraout_a1[0x1a];
      (packet_00->header).fc = bVar7;
      if ((bVar7 & 8) == 0) {
        (packet_00->header).fc = bVar7 | 8;
      }
      else {
        (packet_00->header).fc = bVar7 & 0xf7;
      }
      if (iVar10 == 0) {
        (packet_00->header).fc = (packet_00->header).fc & 0xef;
      }
      else {
        (packet_00->header).fc = (packet_00->header).fc | 0x10;
      }
      zcl_packet_setup_stamp
                (packet_00,extraout_a1[0x15],extraout_a1[0x14],*(uint16_t *)(extraout_a1 + 0x16),
                 *(uint16_t *)(extraout_a1 + 0x18),*extraout_a1,extraout_a1 + 2);
      if (puVar9 == (undefined *)0x0) {
        (packet_00->header).tsn = extraout_a1[0x1e];
        (packet_00->header).fc = (packet_00->header).fc | 0x20;
      }
      else {
        (packet_00->header).tsn = 0xff;
        (packet_00->header).fc = (packet_00->header).fc & 0xdf;
      }
    }
    return;
  }
  (packet->header).src_ep = src_ep;
  (packet->header).dst_ep = dst_ep;
  (packet->header).cluster_id = cluster_id;
  (packet->header).profile_id = profile_id;
  (packet->header).dst_addr.addr_mode = addr_mode;
  uVar8 = addr[1];
  uVar1 = addr[2];
  uVar2 = addr[3];
  uVar3 = addr[4];
  uVar4 = addr[5];
  uVar5 = addr[6];
  uVar6 = addr[7];
  *(uint8_t *)&(packet->header).dst_addr.u = *addr;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 1) = uVar8;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 2) = uVar1;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 3) = uVar2;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 4) = uVar3;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 5) = uVar4;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 6) = uVar5;
  *(uint8_t *)((int)&(packet->header).dst_addr.u + 7) = uVar6;
  return;
}

