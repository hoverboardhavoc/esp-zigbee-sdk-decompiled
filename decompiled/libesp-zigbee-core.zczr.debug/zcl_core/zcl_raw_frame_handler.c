/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_raw_frame_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_raw_frame_handler(int param_1)

{
  size_t unaff_s1;
  int iVar1;
  undefined4 uVar2;
  short sStack_1e;
  int iStack_1c;
  short sStack_18;
  void *pvStack_14;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x78,
                  "zcl_raw_frame_handler","packet");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x79,
                  "zcl_raw_frame_handler","((*core_globals_get()).zcl).raw_frame_cb");
_L0:
    if (unaff_s1 != 0) {
      iVar1 = 1;
      goto _L0;
    }
  }
  else {
    iVar1 = core_globals_get();
    if (*(int *)(iVar1 + 0xd18) == 0) goto _L0;
    iStack_1c = param_1;
    unaff_s1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    sStack_18 = (short)unaff_s1;
    pvStack_14 = (void *)0x0;
    sStack_1e = 0;
    pvStack_14 = calloc(1,unaff_s1);
    if (pvStack_14 == (void *)0x0) goto _L0;
  }
  af_read_bytes(*(undefined4 *)(param_1 + 0x24),&sStack_1e,unaff_s1);
  if (sStack_1e != sStack_18) {
    uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x84,
                          "zcl_raw_frame_handler","offset == frame.payload_length");
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0xd1c) = uVar2;
    return iVar1;
  }
  iVar1 = core_globals_get();
  iVar1 = (**(code **)(iVar1 + 0xd18))(&iStack_1c,*(code **)(iVar1 + 0xd18));
_L0:
  if (pvStack_14 != (void *)0x0) {
    mm_free();
  }
  return iVar1;
}

