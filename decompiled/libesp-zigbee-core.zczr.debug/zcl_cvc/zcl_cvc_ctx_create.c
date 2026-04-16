/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cvc.o -> zcl_cvc_ctx_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_cvc_ctx_create(zcl_cvc_input_t *input,zcl_cvc_ctx_t **cvc_ctx)

{
  _Bool _Var1;
  int8_t iVar2;
  int iVar3;
  uint32_t uVar4;
  int iVar5;
  uint uVar6;
  
  if (input == (zcl_cvc_input_t *)0x0) {
    _Var1 = false;
  }
  else if (input->quant == 0) {
    _Var1 = false;
  }
  else if (cvc_ctx == (zcl_cvc_ctx_t **)0x0) {
    _Var1 = false;
  }
  else {
    (*cvc_ctx)->ep_id = input->ep_id;
    (*cvc_ctx)->curr_tick = 0;
    if (input->duration == 0xffff) {
      uVar4 = 1;
    }
    else {
      uVar4 = input->duration * (uint)input->quant;
    }
    (*cvc_ctx)->total_tick = uVar4;
    if (input->duration == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = (*cvc_ctx)->total_tick;
    }
    (*cvc_ctx)->total_tick = uVar4;
    uVar4 = input->duration;
    if (uVar4 != 0) {
      uVar4 = 100 / input->quant;
    }
    (*cvc_ctx)->delay = uVar4;
    if (input->end < input->begin) {
      iVar2 = -1;
    }
    else {
      iVar2 = '\x01';
    }
    (*cvc_ctx)->sign = iVar2;
    iVar3 = input->end;
    iVar5 = input->begin;
    if (iVar5 < iVar3) {
      uVar6 = iVar3 - iVar5;
    }
    else {
      uVar6 = iVar5 - iVar3;
    }
    (*cvc_ctx)->base_inc = uVar6 / (*cvc_ctx)->total_tick;
    iVar3 = input->end;
    iVar5 = input->begin;
    if (iVar5 < iVar3) {
      uVar6 = iVar3 - iVar5;
    }
    else {
      uVar6 = iVar5 - iVar3;
    }
    (*cvc_ctx)->remainder = uVar6 % (*cvc_ctx)->total_tick;
    (*cvc_ctx)->err_acc = 0;
    (*cvc_ctx)->mode = input->mode;
    (*cvc_ctx)->output = input->begin;
    (*cvc_ctx)->user_cb = input->cb;
    (*cvc_ctx)->data = input->data;
    milli_timer_init(&(*cvc_ctx)->timer,0x10000);
    _Var1 = true;
  }
  return _Var1;
}

