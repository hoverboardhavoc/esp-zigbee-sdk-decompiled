/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_iface_get_pib_attr(undefined4 *param_1,uint param_2,uint *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  byte bVar8;
  undefined1 *puVar9;
  
  puVar9 = (undefined1 *)*param_1;
  if (param_3 == (uint *)0x0) {
    return 2;
  }
  if (param_2 == 0x52) {
    *(byte *)param_3 = (byte)(*(uint *)(puVar9 + 0x28) >> 0x11) & 1;
    return 0;
  }
  if (0x52 < param_2) {
    if (param_2 == 0x5a) {
      *(undefined1 *)param_3 = puVar9[0x1f];
      return 0;
    }
    if (0x5a < param_2) {
      if (param_2 == 0x61) {
        bVar8 = puVar9[0x44];
        *param_3 = *param_3 & 0x7ffffff | (uint)bVar8 << 0x1b;
        *param_3 = (uint)bVar8 << 0x1b | 1 << ((byte)puVar9[0x43] & 0x1f) & 0x7ffffffU;
        return 0;
      }
      if (param_2 < 0x62) {
        if (param_2 == 0x5d) {
          *param_3 = 0;
          return 0;
        }
        if (param_2 == 0x60) {
          bVar8 = puVar9[0x42];
          *param_3 = *param_3 & 0x7ffffff | (uint)bVar8 << 0x1b;
          *param_3 = (uint)bVar8 << 0x1b | 1 << ((byte)puVar9[0x41] & 0x1f) & 0x7ffffffU;
          return 0;
        }
        return 500;
      }
      if (param_2 == 0x62) {
        if ((puVar9[0x9c] & 2) != 0) {
          bVar8 = puVar9[0x42];
          *param_3 = *param_3 & 0x7ffffff | (uint)bVar8 << 0x1b;
          *param_3 = (uint)bVar8 << 0x1b | 1 << ((byte)puVar9[0x41] & 0x1f) & 0x7ffffffU;
          return 0;
        }
        *param_3 = 0;
        return 0;
      }
      if (param_2 == 99) {
        *param_3 = *(uint *)(puVar9 + 0x18);
        return 0;
      }
      return 500;
    }
    if (param_2 == 0x57) {
      *(undefined1 *)param_3 = puVar9[0x21];
      return 0;
    }
    if (0x57 < param_2) {
      if (param_2 == 0x58) {
        *(undefined2 *)param_3 = *(undefined2 *)(puVar9 + 0x1c);
        return 0;
      }
      if (param_2 == 0x59) {
        *(undefined1 *)param_3 = puVar9[0x1e];
        return 0;
      }
      return 500;
    }
    if (param_2 == 0x54) {
      *param_3 = 0xf;
      return 0;
    }
    if (param_2 != 0x55) {
      if (param_2 == 0x53) {
        *(undefined2 *)param_3 = *(undefined2 *)(puVar9 + 8);
        return 0;
      }
      return 500;
    }
    *(undefined2 *)param_3 = *(undefined2 *)(puVar9 + 0x28);
    return 0;
  }
  if (param_2 == 0x4a) {
    uVar1 = puVar9[0x11];
    uVar2 = puVar9[0x12];
    uVar3 = puVar9[0x13];
    uVar4 = puVar9[0x14];
    uVar5 = puVar9[0x15];
    uVar6 = puVar9[0x16];
    uVar7 = puVar9[0x17];
    *(undefined1 *)param_3 = puVar9[0x10];
    *(undefined1 *)((int)param_3 + 1) = uVar1;
    *(undefined1 *)((int)param_3 + 2) = uVar2;
    *(undefined1 *)((int)param_3 + 3) = uVar3;
    *(undefined1 *)(param_3 + 1) = uVar4;
    *(undefined1 *)((int)param_3 + 5) = uVar5;
    *(undefined1 *)((int)param_3 + 6) = uVar6;
    *(undefined1 *)((int)param_3 + 7) = uVar7;
    return 0;
  }
  if (0x4a < param_2) {
    if (param_2 == 0x4e) {
      *(undefined1 *)param_3 = puVar9[0x22];
      return 0;
    }
    if (param_2 < 0x4f) {
      if (param_2 == 0x4b) {
        *(undefined2 *)param_3 = *(undefined2 *)(puVar9 + 0xe);
        return 0;
      }
      if (param_2 == 0x4c) {
        *(undefined1 *)param_3 = puVar9[0xc];
        return 0;
      }
      return 500;
    }
    if (param_2 == 0x4f) {
      *(undefined1 *)param_3 = puVar9[0x20];
      return 0;
    }
    if (param_2 == 0x50) {
      *(undefined2 *)param_3 = *(undefined2 *)(puVar9 + 10);
      return 0;
    }
    return 500;
  }
  if (param_2 == 0x46) {
    *(undefined1 *)param_3 = puVar9[0x23];
    return 0;
  }
  if (0x46 < param_2) {
    if (param_2 == 0x47) {
      *param_3 = 0xf;
      return 0;
    }
    if (param_2 == 0x49) {
      *(undefined1 *)param_3 = puVar9[0xd];
      return 0;
    }
    return 500;
  }
  if (param_2 == 0x41) {
    *(byte *)param_3 = (byte)*(undefined2 *)(puVar9 + 0x2a) & 1;
    return 0;
  }
  if (param_2 != 0x45) {
    if (param_2 == 0x40) {
      uVar1 = puVar9[1];
      uVar2 = puVar9[2];
      uVar3 = puVar9[3];
      uVar4 = puVar9[4];
      uVar5 = puVar9[5];
      uVar6 = puVar9[6];
      uVar7 = puVar9[7];
      *(undefined1 *)param_3 = *puVar9;
      *(undefined1 *)((int)param_3 + 1) = uVar1;
      *(undefined1 *)((int)param_3 + 2) = uVar2;
      *(undefined1 *)((int)param_3 + 3) = uVar3;
      *(undefined1 *)(param_3 + 1) = uVar4;
      *(undefined1 *)((int)param_3 + 5) = uVar5;
      *(undefined1 *)((int)param_3 + 6) = uVar6;
      *(undefined1 *)((int)param_3 + 7) = uVar7;
      return 0;
    }
    return 500;
  }
  *param_3 = *(uint *)(puVar9 + 0x24);
  return 0;
}

