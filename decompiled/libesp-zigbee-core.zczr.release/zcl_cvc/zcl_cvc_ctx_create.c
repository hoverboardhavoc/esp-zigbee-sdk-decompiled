/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cvc.o -> zcl_cvc_ctx_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_cvc_ctx_create(zcl_cvc_input_t *input,zcl_cvc_ctx_t **cvc_ctx)

{
  uint8_t uVar1;
  int iVar2;
  zcl_cvc_ctx_t *pzVar3;
  uint32_t uVar4;
  uint uVar5;
  int iVar6;
  uintptr_t uVar7;
  uint uVar8;
  
  if (input == (zcl_cvc_input_t *)0x0) {
    return false;
  }
  uVar8 = (uint)input->quant;
  if ((uVar8 == 0) || (cvc_ctx == (zcl_cvc_ctx_t **)0x0)) {
    return false;
  }
  pzVar3 = *cvc_ctx;
  pzVar3->ep_id = input->ep_id;
  uVar4 = input->duration;
  pzVar3->curr_tick = 0;
  if (uVar4 == 0xffff) {
    uVar5 = 1;
_L0:
    uVar4 = 100 / uVar8;
  }
  else {
    if (uVar4 != 0) {
      uVar5 = uVar8 * uVar4;
      goto _L0;
    }
    uVar5 = 1;
    uVar4 = 0;
  }
  pzVar3->delay = uVar4;
  iVar2 = input->begin;
  iVar6 = input->end;
  pzVar3->total_tick = uVar5;
  if (iVar6 < iVar2) {
    pzVar3->sign = -1;
  }
  else {
    pzVar3->sign = '\x01';
    if (iVar2 < iVar6) {
      uVar8 = iVar6 - iVar2;
      goto _L0;
    }
  }
  uVar8 = iVar2 - iVar6;
_L0:
  pzVar3->err_acc = 0;
  pzVar3->base_inc = uVar8 / uVar5;
  pzVar3->remainder = uVar8 % uVar5;
  uVar1 = input->mode;
  pzVar3->output = iVar2;
  pzVar3->mode = uVar1;
  uVar7 = input->data;
  pzVar3->user_cb = input->cb;
  pzVar3->data = uVar7;
  milli_timer_init(&pzVar3->timer,0x10000);
  return true;
}

