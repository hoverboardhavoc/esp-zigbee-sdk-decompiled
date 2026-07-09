/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_write_ext_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_frame_write_ext_hdr(undefined4 param_1,int param_2,int param_3)

{
  int unaff_s0;
  undefined1 uStack_22;
  char acStack_21 [13];
  
  zmsg_read_bytes(0,1,acStack_21);
  if (acStack_21[0] < '\0') {
    unaff_s0 = aps_fcf_get_hdr_size();
    if (param_3 == 0) {
      uStack_22 = 1;
      goto _L51;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_frame.c",0xa2,
                  "aps_frame_write_ext_hdr","aps_fcf_has_ext_hdr(fcf)");
  }
  uStack_22 = 2;
_L51:
  zmsg_write_bytes(param_1,unaff_s0,1,&uStack_22);
  if (param_3 == 0) {
    param_3 = param_2;
  }
  uStack_22 = (undefined1)param_3;
  zmsg_write_bytes(param_1,unaff_s0 + 1U & 0xffff,1,&uStack_22);
  return;
}

