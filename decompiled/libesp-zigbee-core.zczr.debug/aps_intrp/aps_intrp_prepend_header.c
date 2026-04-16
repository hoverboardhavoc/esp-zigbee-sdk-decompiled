/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_prepend_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_intrp_prepend_header(zmsg_t *msg,aps_intrp_data_req_t *req)

{
  ezb_addr_mode_t eVar1;
  uint16_t uVar2;
  ezb_shortaddr_t eVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  undefined4 uStack_18;
  uint8_t aps_hdr [7];
  
  uStack_18 = 0;
  aps_hdr[0] = '\0';
  aps_hdr[1] = '\0';
  aps_hdr[2] = '\0';
  if ((msg == (zmsg_t *)0x0) || (req == (aps_intrp_data_req_t *)0x0)) {
    req = (aps_intrp_data_req_t *)
          __assert_func("//build/esp-zigbee/src/core/aps/interpan/aps_intrp.c",0x34,
                        "aps_intrp_prepend_header","msg && req");
  }
  else {
    eVar1 = (req->dst_addr).addr_mode;
    if (eVar1 == '\x01') {
      bVar5 = 0xf;
      goto _L0;
    }
    if (eVar1 != '\x02') {
      bVar5 = 3;
      goto _L0;
    }
  }
  if ((req->dst_addr).u.short_addr < 0xfff8) {
    bVar5 = 3;
  }
  else {
    bVar5 = 0xb;
  }
_L0:
  uVar4 = uStack_18;
  uStack_18 = CONCAT31(uStack_18._1_3_,bVar5);
  if ((bVar5 & 0xc) == 0xc) {
    eVar3 = (req->dst_addr).u.short_addr;
    uStack_18._3_1_ = SUB41(uVar4,3);
    uStack_18._0_3_ = CONCAT12((char)(eVar3 >> 8),CONCAT11((char)eVar3,bVar5));
    puVar6 = (undefined1 *)((int)&uStack_18 + 3);
  }
  else {
    puVar6 = (undefined1 *)((int)&uStack_18 + 1);
  }
  uVar2 = req->cluster_id;
  *puVar6 = (char)uVar2;
  puVar6[1] = (char)(uVar2 >> 8);
  uVar2 = req->profile_id;
  puVar6[2] = (char)uVar2;
  puVar6[3] = (char)(uVar2 >> 8);
  zmsg_prepend_bytes((uint)(puVar6 + (4 - (int)&uStack_18)) & 0xffff);
  return;
}

