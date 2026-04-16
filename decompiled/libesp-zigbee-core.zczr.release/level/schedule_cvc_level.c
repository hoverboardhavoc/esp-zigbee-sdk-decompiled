/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> schedule_cvc_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t schedule_cvc_level(uint8_t ep_id,zcl_cvc_input_t *input)

{
  zcl_attr_desc_t *pzVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  
  pzVar1 = level_srv_get_attr_desc(ep_id,(uint16_t)input);
  eVar3 = 0x86;
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    zcl_cvc_stop(pzVar1->data_p);
    iVar2 = zcl_cvc_ctx_create(input,&pzVar1->data_p);
    eVar3 = '\x01';
    if (iVar2 != 0) {
      zcl_cvc_start(pzVar1->data_p);
      eVar3 = '\0';
    }
  }
  return eVar3;
}

