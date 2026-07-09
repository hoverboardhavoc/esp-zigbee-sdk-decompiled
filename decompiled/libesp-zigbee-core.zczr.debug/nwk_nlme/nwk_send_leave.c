/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_send_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_send_leave(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zmsg_alloc(0x2f);
  if (iVar1 != 0) {
    nwk_build_leave(param_1,param_2,param_3);
    uVar2 = nwk_fwd_send_msg_delayed(iVar1,0);
    return uVar2;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x141,"nwk_send_leave",
                "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((1) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
               );
  iVar1 = nwk_is_joined();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = nwk_is_authed();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

