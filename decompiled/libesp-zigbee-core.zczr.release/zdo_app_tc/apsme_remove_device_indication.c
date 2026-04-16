/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> apsme_remove_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_remove_device_indication(apsme_remove_device_ind_t *ind)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  
  iVar5 = zdo_dev_joined();
  if (((iVar5 != 0) && (iVar5 = nwk_is_device_zr(), iVar5 != 0)) &&
     (iVar5 = zdo_create_mgmt_req(0x34), iVar5 != 0)) {
    puVar6 = (undefined1 *)zdo_mgmt_req_get_param();
    puVar1 = (undefined4 *)((int)&(ind->target_address).field_0 + 4);
    uVar2 = *(undefined2 *)puVar1;
    uVar3 = *(undefined4 *)&(ind->target_address).field_0;
    uVar4 = *puVar1;
    *puVar6 = (char)*(undefined2 *)&(ind->target_address).field_0;
    puVar6[1] = (char)((uint)uVar3 >> 8);
    puVar6[3] = (char)((uint)uVar3 >> 0x18);
    puVar6[5] = (char)((uint)uVar4 >> 8);
    puVar6[2] = (char)((uint)uVar3 >> 0x10);
    puVar6[4] = (char)uVar2;
    puVar6[6] = (char)((uint)uVar4 >> 0x10);
    puVar6[7] = (char)((uint)uVar4 >> 0x18);
    iVar7 = zdo_mgmt_req_get_param(iVar5);
    *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) | 2;
    iVar7 = zdo_mgmt_req_get_param(iVar5);
    *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) & 0xfe;
    zdo_send_mgmt_req(iVar5,0);
    return;
  }
  return;
}

