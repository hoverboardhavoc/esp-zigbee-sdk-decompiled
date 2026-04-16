/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> aps_apsde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_apsde_data_indication(aps_apsde_data_ind_t *ind)

{
  ezb_shortaddr_t eVar1;
  int iVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  uint8_t *puVar5;
  
  eVar1 = (ind->addr_info).grp_addr;
  iVar2 = 0xff;
  if (eVar1 != 0) {
    uVar3 = aps_group_table_find(eVar1);
    while (iVar2 = aps_group_next_endpoint(uVar3,iVar2 + 1U & 0xff), iVar2 != 0xff) {
      uVar4 = random_add_jitter(0,10);
      af_data_indication_deliver_ep(ind,(uint8_t)iVar2,uVar4);
    }
    return;
  }
  if ((ind->addr_info).dst_ep != 0xff) {
    af_data_indication_handler(ind);
    return;
  }
  uVar4 = 0;
  puVar5 = (uint8_t *)0x0;
  while (puVar5 = (uint8_t *)af_device_get_next_endpoint_desc(puVar5), puVar5 != (uint8_t *)0x0) {
    if ((*puVar5 != 0xff) && (*(uint16_t *)(puVar5 + 2) == (ind->addr_info).profile_id)) {
      af_data_indication_deliver_ep(ind,*puVar5,uVar4);
      uVar4 = random_add_jitter(uVar4,10);
    }
  }
  zmsg_free(ind->asdu);
  return;
}

