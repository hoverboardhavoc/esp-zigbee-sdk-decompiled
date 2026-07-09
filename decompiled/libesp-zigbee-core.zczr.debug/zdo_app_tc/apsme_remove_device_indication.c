/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> apsme_remove_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_remove_device_indication(int param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar4 = zdo_dev_joined();
  if (((iVar4 != 0) && (iVar4 = nwk_is_device_zr(), iVar4 != 0)) &&
     (iVar4 = zdo_create_mgmt_req(0x34), iVar4 != 0)) {
    puVar5 = (undefined1 *)zdo_mgmt_req_get_param();
    uVar1 = *(undefined4 *)(param_1 + 8);
    uVar2 = *(undefined2 *)(param_1 + 0xc);
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    *puVar5 = (char)*(undefined2 *)(param_1 + 8);
    puVar5[1] = (char)((uint)uVar1 >> 8);
    puVar5[2] = (char)((uint)uVar1 >> 0x10);
    puVar5[3] = (char)((uint)uVar1 >> 0x18);
    puVar5[4] = (char)uVar2;
    puVar5[5] = (char)((uint)uVar3 >> 8);
    puVar5[6] = (char)((uint)uVar3 >> 0x10);
    puVar5[7] = (char)((uint)uVar3 >> 0x18);
    iVar6 = zdo_mgmt_req_get_param(iVar4);
    *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) | 2;
    iVar6 = zdo_mgmt_req_get_param(iVar4);
    *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfe;
    zdo_send_mgmt_req(iVar4,0);
  }
  return;
}

