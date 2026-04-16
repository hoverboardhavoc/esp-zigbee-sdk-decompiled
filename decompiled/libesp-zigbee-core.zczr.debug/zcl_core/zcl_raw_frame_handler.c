/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_core.c",0x7a,"zcl_raw_frame_handler","packet"
                 );
_L0:
    value = "((*core_globals_get()).zcl).raw_frame_cb";
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_core.c",0x7b,"zcl_raw_frame_handler");
_L0:
    if (unaff_s1 != 0) {
      uVar1 = 1;
      goto _L0;
    }
  }
  else {
    iVar2 = core_globals_get();
    if (*(int *)(iVar2 + 0xd7c) == 0) goto _L0;
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
    uVar3 = __assert_func("//build/esp-zigbee/src/core/zcl/zcl_core.c",0x86,"zcl_raw_frame_handler",
                          "offset == frame.payload_length");
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xd80) = uVar3;
    return SUB41(iVar2,0);
  }
  iVar2 = core_globals_get();
  uVar1 = (**(code **)(iVar2 + 0xd7c))(&stack0xffffffe4,*(code **)(iVar2 + 0xd7c));
_L0:
  if (frame._4_4_ != 0) {
    mm_free();
  }
  return (_Bool)uVar1;
}

