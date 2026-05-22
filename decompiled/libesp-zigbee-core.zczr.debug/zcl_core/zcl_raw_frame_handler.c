/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_raw_frame_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_raw_frame_handler(zcl_packet_t *packet)

{
  size_t unaff_s1;
  undefined1 uVar1;
  int iVar2;
  char *value;
  undefined4 uVar3;
  uint16_t uStack_1e;
  zcl_packet_t *pzStack_1c;
  uint16_t offset;
  zcl_raw_frame_t frame;
  
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x7a,
                  "zcl_raw_frame_handler","packet");
_L0:
    value = "((*core_globals_get()).zcl).raw_frame_cb";
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x7b,
                  "zcl_raw_frame_handler");
_L0:
    if (unaff_s1 != 0) {
      uVar1 = 1;
      goto _L0;
    }
  }
  else {
    iVar2 = core_globals_get();
    if (*(int *)(iVar2 + 0xd18) == 0) goto _L0;
    pzStack_1c = packet;
    unaff_s1 = zmsg_get_length(packet->payload);
    frame.header._0_2_ = (uint16_t)unaff_s1;
    frame.payload_length = 0;
    frame._6_2_ = 0;
    uStack_1e = 0;
    value = (char *)calloc(1,unaff_s1);
    frame._4_4_ = value;
    if ((uint8_t *)value == (uint8_t *)0x0) goto _L0;
  }
  af_read_bytes(packet->payload,&uStack_1e,(uint16_t)unaff_s1,(uint8_t *)value);
  if (uStack_1e != (uint16_t)frame.header) {
    uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x86,
                          "zcl_raw_frame_handler","offset == frame.payload_length");
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xd1c) = uVar3;
    return SUB41(iVar2,0);
  }
  iVar2 = core_globals_get();
  uVar1 = (**(code **)(iVar2 + 0xd18))(&stack0xffffffe4,*(code **)(iVar2 + 0xd18));
_L0:
  if (frame._4_4_ != 0) {
    mm_free();
  }
  return (_Bool)uVar1;
}

