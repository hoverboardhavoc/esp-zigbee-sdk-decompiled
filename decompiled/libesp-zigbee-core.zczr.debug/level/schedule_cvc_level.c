/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> schedule_cvc_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t schedule_cvc_level(uint8_t ep_id,zcl_cvc_input_t *input)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  
  pzVar2 = level_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    eVar1 = 0x86;
  }
  else {
    zcl_cvc_stop(pzVar2->data_p);
    iVar3 = zcl_cvc_ctx_create(input,&pzVar2->data_p);
    if (iVar3 == 0) {
      eVar1 = '\x01';
    }
    else {
      zcl_cvc_start(pzVar2->data_p);
      eVar1 = '\0';
    }
  }
  return eVar1;
}

