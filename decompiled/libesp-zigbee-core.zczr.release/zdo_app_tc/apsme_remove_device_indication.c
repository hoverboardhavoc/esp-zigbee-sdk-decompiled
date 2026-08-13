/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> apsme_remove_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_remove_device_indication(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar4 = zdo_dev_joined();
  if (((iVar4 != 0) && (iVar4 = nwk_is_device_zczr(), iVar4 != 0)) &&
     (iVar4 = zdo_create_mgmt_req(0x34), iVar4 != 0)) {
    puVar5 = (undefined1 *)zdo_mgmt_req_get_param();
    uVar1 = *(undefined2 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 8);
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    *puVar5 = (char)*(undefined2 *)(param_1 + 8);
    puVar5[1] = (char)((uint)uVar2 >> 8);
    puVar5[3] = (char)((uint)uVar2 >> 0x18);
    puVar5[5] = (char)((uint)uVar3 >> 8);
    puVar5[2] = (char)((uint)uVar2 >> 0x10);
    puVar5[4] = (char)uVar1;
    puVar5[6] = (char)((uint)uVar3 >> 0x10);
    puVar5[7] = (char)((uint)uVar3 >> 0x18);
    iVar6 = zdo_mgmt_req_get_param(iVar4);
    *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) | 2;
    iVar6 = zdo_mgmt_req_get_param(iVar4);
    *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfe;
    zdo_send_mgmt_req(iVar4,0);
    return;
  }
  return;
}

